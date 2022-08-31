const debounce = require("debounce");
const fs = require("fs");
const log = require("../log");

const execSync = require("child_process").execSync;

const allowOffline = false;

const LAYER_DEBOUNCE = 50;
const STATE = {
  activeLayer: 0,
};

const FILE_PREFIX = "/tmp/zsa";
const writeFile = (name, data) =>
  fs.writeFileSync(`${FILE_PREFIX}-${name}`, data.toString());

const execOptions = { stdio: "pipe" };

const nativeSet = (layer) => {
  const layers = {
    0: "com.apple.keylayout.Colemak",
    1: "com.apple.keylayout.US",
  };
  const im = layers[layer] || layer;
  if (im) execSync(`/usr/local/bin/im-select ${im}`, execOptions);
};

const nativeGet = () => {
  const result = execSync(`/usr/local/bin/im-select`, execOptions)
    .toString()
    .replace(/\n/gi, "");
  const layer = [
    "com.apple.keylayout.Colemak",
    "com.apple.keylayout.US",
  ].indexOf(result);
  return layer < 0 ? 1 : layer;
};

module.exports = (ctx) => {
  ctx.layer = {
    get activeLayer() {
      return STATE.activeLayer;
    },
  };
  ctx.register([
    {
      type: "out",
      name: "layer_set",
      allowOffline,
      handler: debounce(async (_, layer, code) => {
        console.log(ctx.device, layer, code);
        if (!ctx.device) {
          await nativeSet(layer);
          STATE.activeLayer = layer;
          writeFile("layer-state", layer);
          return;
        }
        if (layer === STATE.activeLayer) {
          log("setLayer skipped", layer, STATE.activeLayer);
          return;
        }
        const formatted = parseInt(layer, 10);
        ctx.writeCommand(code, formatted);
      }, LAYER_DEBOUNCE),
    },
    {
      type: "out",
      name: "layer_get",
      allowOffline,
      handler: () => (!ctx.device ? nativeGet() : STATE.activeLayer),
    },
    {
      type: "in",
      name: "layer_changed",
      handler(payload) {
        const activeLayer = payload[0] - 1;
        STATE.activeLayer = activeLayer;
        writeFile("layer-state", activeLayer);
      },
    },
  ]);
};
