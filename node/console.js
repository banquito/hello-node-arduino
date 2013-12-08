
var readline = require('readline');
var Grua = require('./grua.js');
var grua = new Grua();

grua.open(function() {
  readLine = readline.createInterface(process.stdin, process.stdout);
  readLine.setPrompt('grua> ');
  readLine.prompt();
  
  readLine.on('line', function(line) {
    var command = line.trim();
    if (command == "q") {
      readLine.close();
    } else {
      grua.eval(command);
    }
    readLine.prompt();
  }).on('close', function() {
    grua.close(function () {
      process.exit(0);
    });
  });

});