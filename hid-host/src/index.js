const Fastify = require("fastify");
const log = require("./log");
const hid = require("./hid");
const fastify = Fastify({ logger: false });

fastify.route({
  method: "POST",
  url: "/exec/:id",
  schema: {
    params: {
      id: { type: "string" },
    },
  },
  handler: (request, reply) => {
    log("aaa");
    try {
      const result = hid.exec(request.params.id, request.body);
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
