const debounce = require("debounce");
const fs = require("fs");
const log = require("../log");

const LAYER_DEBOUNCE = 50;
const STATE = {
  activeLayer: 0,
};

const FILE_PREFIX = "/tmp/zsa";
const writeFile = (name, data) =>
  fs.writeFileSync(`${FILE_PREFIX}-${name}`, data);

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
      handler: debounce((_, layer, code) => {
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
      handler: () => STATE.activeLayer,
    },
    {
      type: "in",
      name: "layer_changed",
      handler(payload) {
        const activeLayer = payload[0] - 1;
        STATE.activeLayer = activeLayer;
        writeFile("layer-state", activeLayer.toString());
      },
    },
  ]);
};
