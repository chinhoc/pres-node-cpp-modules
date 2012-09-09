#include <v8.h>
#include <node.h>
#include <stdlib.h>

using namespace v8;

static Handle<Value> 
TransformString( const Arguments& args ) {
	HandleScope scope;

	// args[0] is a v8::Value with to* methods
	Local<String> str = args[0]->ToString();

	return scope.Close( String::Concat( String::New("Yep, I have modified: "), str ));
}


static void 
init( Handle<Object> target ) {
	NODE_SET_METHOD(target, "transformString", TransformString);
}

NODE_MODULE(funcArgs, init);
