var moduleTest = require('../build/Release/simpleModule.node');

console.log("\nType of module: "+moduleTest);
console.log("\nAvailable method: "+moduleTest.randomNumber);

console.log("\nCalling randomNumber: "+moduleTest.randomNumber());
