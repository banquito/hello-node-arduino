var SerialPort = require('serialport').SerialPort;
var portName = '/dev/ttyACM0';

var Grua = function() {
  var port = new SerialPort(portName, {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false
  });

  this.open = function(cb) {
    port.open(function(err) {
      cb(err)
    });
  };

  this.close = function(cb) {
    port.close(function(err) {
      cb(err);
    });
  };

  this.left = function() {
    port.write('9');
  };

  this.right = function() {
    port.write('0');
  };
};

module.exports = Grua;