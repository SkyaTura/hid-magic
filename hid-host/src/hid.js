const HID = require("node-hid");
const log = require("./log");
const utils = require("./utils");
const modules = require("./modules");
const enums = require("./enums");

const RESTART_DELAY = 5000;

const HID_REF = {
  manufacturer: "ZSA",
  product: "Moonlander Mark I",
  usagePage: 0xff60,
  usage: 0x61,
};

let device = null;

const handlers = [];

const ctx = {
  enums,
  registerOne(item) {
    if (item.name in enums.codes) return;
    handlers.push(item);
  },
  register(items) {
    items.forEach((item) => this.registerOne(item));
  },
  writeCommand(id, data) {
    log("out", { id, data });
    const bytes = utils.commandToBytes(id, data);
    device.write(bytes);
    return bytes;
  },
  get device() {
    return device;
  },
  exec(id, data) {
    const code = enums.codes.indexOf(id);
    const commands = handlers.filter(
      (command) =>
        command.type === "out" &&
        command.name === id &&
        (command.allowOffline || !!this.device)
    );
    if (!commands.length) {
      if (!device) {
        log("Device is no connected.");
        return;
      }
      log("Unknown command: ", id);
      return;
    }
    commands.forEach((command) => this.execOut(command, data, code));
  },
  execOne(id, data) {
    const code = enums.codes.indexOf(id);
    const command = handlers.find(
      (command) =>
        command.type === "out" &&
        command.name === id &&
        (command.allowOffline || !!this.device)
    );
    if (!command) {
      if (!device) {
        console.error("Device is no connected.");
        return null;
      }
      log("Unknown command: ", id);
      return null;
    }
    return this.execOut(command, data, code);
  },
  execIn(listener, data, code) {
    const { format, handler, condition } = listener;
    const formatted = format ? format(data) : data;
    if (condition && !condition(formatted, data)) return;

    if (handler) {
      return handler(formatted, data, code);
    }

    this.writeCommand(code, formatted);
  },

  execOut(command, data, code) {
    const { format, handler, condition } = command;
    const formatted = format ? format(data) : data;
    if (condition && !condition(formatted, data)) return;

    if (handler) {
      return handler(formatted, data, code);
    }

    this.writeCommand(code, formatted);
  },
};

modules.forEach((item) => item(ctx));

const list = () => HID.devices().filter(utils.match(HID_REF));

const connect = async () => {
  log("Fetching device list");
  const devices = list();
  log("Devices found: ", devices.length);

  log("Finding Keyboard");
  const keyboard = devices[0];

  if (!keyboard) {
    log("Keyboard not found!");
    restart();
    return;
  }

  log("Keyboard found:", keyboard);
  device = new HID.HID(keyboard.path);

  device.on("error", () => {
    console.error("Keyboard error");
    handlers
      .filter((item) => item.type === "keyboard_error")
      .forEach((item) => item.handler(device));
    start();
  });
  device.on("data", ([code, ...data]) => {
    const name = enums.codes[code];
    log("in", { code, name, data: data.join(" ") });
    if (!name) return;
    const listeners = handlers.filter(
      (listener) => listener.type === "in" && listener.name === name
    );
    if (!listeners.length) {
      log("Unknown listener: ", name);
      return;
    }
    listeners.forEach((listener) => ctx.execIn(listener, data, code));
  });

  console.info("Keyboard connected.");
  handlers
    .filter((item) => item.type === "keyboard_connected")
    .forEach((item) => item.handler(device));
};

function start() {
  return connect().catch(restart);
}

function restart() {
  device = null;
  setTimeout(start, RESTART_DELAY);
}

exports.start = start;
exports.exec = ctx.exec;
exports.ctx = ctx;
exports.list = list;
