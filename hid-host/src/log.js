module.exports = (...params) => {
  if (process.env.DEBUG !== "true") return;
  console.log(...params);
};
