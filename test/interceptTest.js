var intercept = require('../build/Release/intercept.node'),
	func1 = function (name) { console.log("request to "+name);},
	func2 = function (name, value) { console.log("request to "+name+" with "+value);},
	obj = intercept.createInterception(func1, func2);

// access property toto of obj will trigger the calback func1
var toto = obj.toto;

// changing property toto of obj will trigger func2
obj.toto = "rototo";


