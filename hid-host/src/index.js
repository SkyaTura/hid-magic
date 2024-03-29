const Fastify = require("fastify");
const CORS = require("fastify-cors");
const log = require("./log");
const hid = require("./hid");
const fastify = Fastify({ logger: false });

fastify.register(require("fastify-cors"), {
  // put your options here
});

fastify.route({
  method: "POST",
  url: "/get/:id",
  schema: {
    params: {
      id: { type: "string" },
    },
  },
  handler: async (request, reply) => {
    try {
      const result = await hid.ctx.execOne(request.params.id, request.body);
      if (result === null) throw new Error("Unknown result");
      reply.code(200).send(result);
    } catch (error) {
      log(error);
      reply.code(500).send(error);
    }
  },
});

fastify.route({
  method: "POST",
  url: "/exec/:id",
  schema: {
    params: {
      id: { type: "string" },
    },
  },
  handler: async (request, reply) => {
    try {
      const result = await hid.ctx.exec(request.params.id, request.body);
      reply.code(200).send({ result });
    } catch (error) {
      console.error(error);
      reply.code(500).send(error);
    }
  },
});

const start = async () => {
  try {
    console.info("Starting fastify");
    await fastify.listen(9098, "127.0.0.1");

    console.info("Starting node-hid");
    hid.start();
  } catch (err) {
    console.error("fastify failed to start");
    fastify.log.error(err);
    process.exit(1);
  }
};

start();
