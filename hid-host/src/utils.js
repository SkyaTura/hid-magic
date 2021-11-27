const PACKET_PADDING = 64

const dataToBytes = (data = null) => {
  if (typeof data === 'string') return strToBytes(data)
  if (Array.isArray(data)) return data
  return [data]
}

const strToBytes = (str) => [...str.split('').map(c => c.charCodeAt(0)), 0]

const lengthToBytes = exports.lengthToBytes = (length) => {
  const lengthBuffer = new ArrayBuffer(4)
  const lengthDataView = new DataView(lengthBuffer)
  lengthDataView.setUint32(0, length, true)
  return new Uint8Array(lengthBuffer)
}

const commandToBytes = (id, data) => {
  const bytes = dataToBytes(data).filter(item => ![null, undefined].includes(item))
  const unpadded = [
    0, id,
    ...lengthToBytes(bytes.length),
    ...bytes
  ];
  const padding = new Array(PACKET_PADDING - (unpadded.length % PACKET_PADDING)).fill(0)
  return [ ...unpadded, ...padding ]
}

const bytesToCommand = buffer => [...buffer]

const match = (ref) => (item) => Object.entries(ref).every(([key, value]) => item[key] === value)

exports.commandToBytes = commandToBytes
exports.bytesToCommand = bytesToCommand
exports.match = match
