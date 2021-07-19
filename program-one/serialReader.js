const SerialPort = require('serialport');
const fs = require('fs');

const portName = 'COM3';

const serialReader = () => {
  console.log('Reading data');
  const myport = new SerialPort(portName);
  const Readline = SerialPort.parsers.Readline;
  const parser = new Readline();
  myport.pipe(parser);
  parser.on('data', (data) => {
    fs.writeFile('./test.txt', data, (err) => {
      //console.log(err);
    });
    console.log(data);
  });
};
serialReader();
module.exports = serialReader;
