#include <v8.h>
#include <node.h>
#include <stdlib.h>

static v8::Handle<v8::Value> RandomNumber( const v8::Arguments& args ) {
	v8::HandleScope scope;

	return scope.Close( v8::Integer::New( rand() % 10 ) );
}


static void init( v8::Handle<v8::Object> target ) {
	NODE_SET_METHOD(target, "randomNumber", RandomNumber);
}

NODE_MODULE(simpleModule, init);
