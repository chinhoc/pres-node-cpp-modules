# pres-node-cpp-modules


## About
Resources for http://www.meetup.com/Strasbourg-Web/events/75138492/

Simple C++ code examples illustrating the capabilities of nodejs'cpp modules


## Requirements
*node-gyp* for building C++ to node module

## Use
### Compile with node-gyp
	node-gyp configure
	node-gyp build

### Test with the files in test folder
	node tests/simpleModuleTest.js
	node tests/funcArgsTest.js
	node tests/interceptTest.js

## Acknowledgements
Code example taking mostly from:
[Konstantin Käfer's very good tutorial](https://github.com/kkaefer/node-cpp-modules)
[Nodejs C++ addon documentation](http://nodejs.org/api/addons.html)
[Daniel Ennis's magic utility](https://github.com/aikar/magic)
