const Axios = require("axios");
const https = require("https");
const axios = Axios.create({
  baseURL: "https://127.0.0.1:2999/liveclientdata/",
  httpsAgent: new https.Agent({
    rejectUnauthorized: false,
  }),
});

const POOLING_RATE = 1000;
let interval = null;

const clear = () => {
  if (!interval) return;
  clearInterval(interval);
  interval = null;
};
const knownDragons = [
  null,
  "_elder", // This is a Placeholder for dealing with Elder dragon in the Future
  "Earth",
  "Water",
  "Air",
  "Fire",
  "Hextech",
  "Chemtech",
];
const knownSpells = [
  [],
  ["Barreira", "Barrier"],
  ["Purificar", "Cleanse"],
  ["Incendiar", "Ignite"],
  ["Exaustão", "Exhaust"],
  ["Flash"],
  ["Fantasma", "Ghost"],
  ["Curar", "Heal"],
  ["Clareza", "Clarity"],
  ["Golpear", "Smite"],
  ["Marca", "To the King!", "Poro Toss", "Ao Rei!", "Arremesso de Poro"],
  ["Teleporte", "Teleport"],
  [
    "Placeholder",
    "Placeholder and Auto-Smite",
    "A definir",
    "Placeholder e Golpear automático",
  ],
];
const getSpellId = (name) => {
  const index = knownSpells.findIndex((item) => item.indexOf(name) > -1);
  return index < 0 ? 0 : index;
};

const tickFactory = (hid) => async () => {
  const response = await axios.get("/allgamedata").catch(() => null);
  if (!response) {
    hid.exec("sendLolInfo", null);
    return;
  }
  const game = response.data;
  const me = game.allPlayers.find(
    (player) => player.summonerName === game.activePlayer.summonerName
  );
  const teamOrderPlayers = game.allPlayers.filter(
    (player) => player.team === "ORDER"
  );
  const teamChaosPlayers = game.allPlayers.filter(
    (player) => player.team === "CHAOS"
  );
  const isDead = (player) => {
    if (!player) return 0;
    return player.isDead ? 1 : 2;
  };
  const indexedPlayers = game.allPlayers.reduce(
    (acc, player) => ({ ...acc, [player.summonerName]: player }),
    {}
  );
  const teamOrder = Array(5)
    .fill(0)
    .map((_, index) => teamOrderPlayers[index])
    .map(isDead);
  const teamChaos = Array(5)
    .fill(0)
    .map((_, index) => teamChaosPlayers[index])
    .map(isDead);

  const events = game.events.Events;
  const minionSpawn = events.some(
    (event) => event.EventName === "MinionsSpawning"
  )
    ? 1
    : 0;
  const [orderDragons, chaosDragons] = events
    .reduce(
      (acc, event) => {
        if (event.EventName !== "DragonKill") return acc;
        const team = indexedPlayers[event.KillerName].team === "ORDER" ? 0 : 1;
        const dragonId = knownDragons.indexOf(event.DragonType);
        if (dragonId < 0) return acc;
        acc[team].push(dragonId);
        return acc;
      },
      [[], []]
    )
    .map((dragons) =>
      Array(4)
        .fill(0)
        .map((_, i) => dragons[i] ?? 0)
    );

  const spells = {
    d: getSpellId(me.summonerSpells.summonerSpellOne.displayName),
    d: getSpellId(me.summonerSpells.summonerSpellTwo.displayName),
  };

  const abilities = ["Q", "W", "E", "R"].map((key) => {
    const ability = game.activePlayer.abilities[key];
    if (!ability) return 0;
    return ability.abilityLevel ?? 0;
  });

  const items = Array(7).fill(0);
  const getItemValue = (item) => {
    if (item.consumable) return 2;
    if (item.canUse) return 1;
    return 0;
  };
  me.items.forEach((item) => {
    items[item.slot] = getItemValue(item);
  });

  const result = {
    teamOrder,
    teamChaos,
    abilities,
    items,
    spells,
    orderDragons,
    chaosDragons,
    isDead: me.isDead ? 1 : 0,
  };
  hid.exec("sendLolInfo", result);
};
const start = (hid) => {
  if (interval) return;
  const tick = tickFactory(hid);
  interval = setInterval(tick, POOLING_RATE);
  tick();
};

exports.clear = clear;
exports.start = start;
