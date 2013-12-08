
/**
 * Module dependencies.
 */
var app = require('express.io')();
var express = require('express');
var routes = require('./routes');
var path = require('path');

app.http().io()

// Setup the ready route, and emit talk event.
app.io.route('ready', function(req) {
    req.io.emit('talk', {
        message: 'io event from an io route on the server'
    })
})

// all environments
app.set('port', process.env.PORT || 3000);
app.set('views', __dirname + '/views');
app.set('view engine', 'ejs');
app.use(express.favicon());
app.use(express.logger('dev'));
app.use(express.bodyParser());
app.use(express.methodOverride());
app.use(app.router);
app.use(express.static(path.join(__dirname, 'public')));

// development only
if ('development' == app.get('env')) {
  app.use(express.errorHandler());
}

// Setup a rote for grua event
var Grua = require('../grua.js');
var grua = new Grua();
grua.open();
app.io.route('grua', function(req) {
    var command =  req.data;
    console.log(command);
    grua.eval(command);
})

// Setup routes
app.get('/', routes.index);

app.listen(app.get('port'), function(){
  console.log('Express server listening on port ' + app.get('port'));
});
