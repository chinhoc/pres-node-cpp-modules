#include "wrappy.h"

using namespace v8;
using namespace node;

Persistent<Function> Wrappy::constructor;

void 
Wrappy::Init( Handle<Object> target) {

	// v8 Function template for constructor
	// Why ? Because there is no class per say in javascript, there are function constructor though
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);

	// Using a symbol to avoid having already defined one
	Local<String> name = String::NewSymbol("Wrappy");

	// This is useful because object Wrappy will be created using FunctionTemplate
	tpl->SetClassName(name);

	// ObjectWrap uses the internal field to store the wrapped pointer
	tpl->InstanceTemplate()->SetInternalFieldCount(1);
	constructor = Persistent<Function>::New(tpl->GetFunction());

	NODE_SET_PROTOTYPE_METHOD(constructor, "add", Add);

	// Adds the property to every instance of object created with this template
	target->Set(name, constructor);
}


Handle<Value> 
Wrappy::New(const Arguments& args) {
	HandleScope scope;

	// Instanciate the class in C++ and wraps it
	Wrappy* obj = new Wrappy();
	obj->Wrap(args.This());


	return args.This();
}


Handle<Value>
Add (const Arguments& args) {
	HandleScope scope;

	// Some test on arguments is possible
	if(args.Length() < 1) {
		return ThrowException(Exception::TypeError(String::New("There must be at least one argument !")));
	}

	if(!args[0]->IsNumber()) {
		return ThrowException(Exception::TypeError(String::New("First argument must be a number!")));
	}

	// Unwrap object using node::Unwrap 
	Wrappy* obj = ObjectWrap::Unwrap<Wrappy>(args.This());

	// Makes the addition
	obj->m_number += args[0]->NumberValue();

	return scope.Close(Number::New(obj->m_number));
}