# pres-node-cpp-modules


## About
Resources for http://www.meetup.com/Strasbourg-Web/events/75138492/

## Requirements
node-gyp

## Use
### Compile with node-gyp
	node-gyp configure
	node-gyp build

### Test with the files in test folder
	node tests/simpleModuleTest.js
	node tests/funcArgsTest.js
	node tests/interceptTest.js