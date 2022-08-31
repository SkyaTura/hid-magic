const ActiveWindow = require("active-win");

const POOLING_RATE = 500;
const OPTIONS = {
  screenRecordingPermission: true,
};
let interval = null;

module.exports = (ctx) => {
  const tick = async () => {
    const activeWindow = await ActiveWindow(OPTIONS);
    console.log(activeWindow);
    // TODO: Implement per-app-settings. I decided to pause this feature because I don't actually need it right now
  };
  const start = () => {
    if (interval) return;
    interval = setInterval(tick, POOLING_RATE);
  };
  const clear = () => {
    clearInterval(interval);
    interval = null;
  };

  ctx.register([
    {
      type: "keyboard_connected",
      handler: start,
    },
    {
      type: "keyboard_error",
      handler: clear,
    },
  ]);
};
