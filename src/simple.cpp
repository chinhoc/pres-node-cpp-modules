#include <v8.h>
#include <node.h>
#include <stdlib.h>

static v8::Handle<v8::Value> 
RandomNumber( const v8::Arguments& args ) {
	// Everything inside RandomNumber is within this scope
	// The intelligence behind it is that eveything will be cleared once method exits
	v8::HandleScope scope;

	// Method Close() of HandleScope returns the value in parameter inside the previous scope (the caller's)
	return scope.Close( v8::Integer::New( rand() % 10 ) );
}


static void 
Init( v8::Handle<v8::Object> target ) {
	NODE_SET_METHOD(target, "randomNumber", RandomNumber);
}

NODE_MODULE(simpleModule, Init);
