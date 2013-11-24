
var readline = require('readline');
var Grua = require('./grua.js');
var grua = new Grua();

grua.open(function() {
  rl = readline.createInterface(process.stdin, process.stdout);
  rl.setPrompt('grua> ');
  rl.prompt();
  
  rl.on('line', function(line) {
    var command = line.trim();
    if (command == "l") {
      grua.left();
    } else if (command == "r") {
      grua.right();
    } else if (command == "q") {
      rl.close();
    }
    rl.prompt();
  }).on('close', function() {
    grua.close(function () {
      process.exit(0);
    });
  });

});