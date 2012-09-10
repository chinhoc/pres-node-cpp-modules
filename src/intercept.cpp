#include <v8.h>
#include <node.h>

using namespace v8;

Persistent<ObjectTemplate> interceptObj;

Handle<Value>
getInterceptor(Local<String> name, const AccessorInfo& info) {
    Handle<Object> object = info.Holder();
    Handle<Function> getter = Handle<Function>::Cast(object->GetInternalField(0));
    
    Handle<Value> args[1] = {name};
    
    return getter->Call(object, 1, args);
}

Handle<Value>
setInterceptor(Local<String> name, Local<Value> value, const AccessorInfo& info) {
    Handle<Object> object = info.Holder();
    Handle<Function> setter = Handle<Function>::Cast(object->GetInternalField(1));
    
    Handle<Value> args[2] = {name, value};
    
    return setter->Call(object, 2, args);
}

static Handle<Value> 
CreateInterception( const Arguments& args ) {

    HandleScope scope;

    Handle<Object> object = interceptObj->NewInstance();
    
    object->SetInternalField(0, args[0]);
    object->SetInternalField(1, args[1]);

    return scope.Close(object);
}

static void 
init( Handle<Object> target ) {

	interceptObj = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
    interceptObj->SetInternalFieldCount(2);
    interceptObj->SetNamedPropertyHandler(getInterceptor, setInterceptor);
	NODE_SET_METHOD(target, "createInterception", CreateInterception);
}

NODE_MODULE(intercept, init);