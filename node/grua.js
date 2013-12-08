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

  port.on('error', function(err) {
    console.log(err);
  });

  this.open = function(cb) {
    port.open(function(err) {
      if (err) console.log(err);
      cb(err)
    });
  };

  this.close = function(cb) {
    port.close(function(err) {
      cb(err);
    });
  };

  this.armUp = function() {
    this.eval('arm.up');
  };

  this.armDown = function() {
    this.eval('arm.down');
  };

  this.loadUp = function() {
    this.eval('arm.up');
  };

  this.loadDown = function() {
    this.eval('arm.down');
  };  

  this.eval = function(command) {
    port.write(command + '\n');
  };  
};

module.exports = Grua;