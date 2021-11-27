const HID = require("node-hid");
const log = require("./log");
const utils = require("./utils");
const fs = require("fs");
const lol = require("./lol");

const STATE = {
  layerState: 0,
};
const RESTART_DELAY = 5000;

const FILE_PREFIX = "/tmp/zsa";
const writeFile = (name, data) =>
  fs.writeFileSync(`${FILE_PREFIX}-${name}`, data);

const HID_REF = {
  manufacturer: "ZSA",
  product: "Moonlander Mark I",
  usagePage: 0xff60,
  usage: 0x61,
};

let device = null;

const testData = null && [
  1,
  0,
  ...[1, 1, 1, 1],
  ...[1, 1, 1, 1, 1, 1, 1],
  ...[1, 2, 0, 1, 1],
  ...[1, 1, 0, 2, 1],
  ...[1, 1],
  ...[0, 0, 0, 0],
  ...[0, 0, 0, 0],
];
const commands = {
  setLayer: {
    code: 129,
    condition: (layer) => layer !== STATE.layerState,
    format: (layer) => parseInt(layer, 10),
  },
  getLayer: {
    handler: () => STATE.layerState,
  },
  sendLolInfo: {
    code: 130,
    condition: () => STATE.layerState === 2,
    format: (data) =>
      !data
        ? testData || [0]
        : [
            1, // Game running
            data.isDead, // Is alive
            ...data.abilities, // 4 abilities
            ...data.items, // 7 items
            ...data.teamOrder, // 5 players
            ...data.teamChaos, // 5 players
            data.spells.d, // 1 spell
            data.spells.f, // 1 spell
            ...data.orderDragons, // 4 dragons
            ...data.chaosDragons, // 4 dragons
          ],
  },
};

const listeners = {
  [131]: (payload) => {
    const layerState = payload[0] - 1;
    writeFile("layer-state", layerState.toString());
    STATE.layerState = layerState;
    switch (layerState) {
      case 2: {
        lol.start(exports);
        break;
      }
      case 0:
      case 1:
      default:
        lol.clear();
    }
  },
  [132]: (payload) => log("LOL Response: ", payload.join("")),
};

const writeCommand = (id, data) => {
  log("out", { id, data });
  const bytes = utils.commandToBytes(id, data);
  device.write(bytes);
  return bytes;
};

const exec = (id, data) => {
  if (!device) {
    console.error("Device is no connected.");
    return;
  }
  const command = commands[id];
  if (!command) {
    log("Unknown command: ", id);
    return;
  }
  const { code, format, handler, condition } = command;
  const formatted = format ? format(data) : data;
  if (condition && !condition(formatted, data)) {
    return;
  }
  if (handler) {
    handler(formatted, data);
    return;
  }
  writeCommand(code, formatted);
};

const list = () => HID.devices().filter(utils.match(HID_REF));

const connect = async () => {
  console.info("Fetching device list");
  const devices = list();
  console.info("Devices found: ", devices.length);

  console.info("Finding Keyboard");
  const keyboard = devices[0];

  if (!keyboard) {
    console.info("Keyboard not found!");
    restart();
    return;
  }

  console.info("Keyboard found:", keyboard);
  device = new HID.HID(keyboard.path);

  device.on("error", start);
  device.on("data", (data) => {
    const [code, ...payload] = [...data];
    const listener = listeners[code];
    log("in", { code, data: payload.join(" ") });
    if (!listener) return;
    listener(payload);
  });

  console.info("Keyboard connected.");
};

function start() {
  return connect().catch(restart);
}

function restart() {
  device = null;
  setTimeout(start, RESTART_DELAY);
}

exports.start = start;
exports.exec = exec;
exports.list = list;
