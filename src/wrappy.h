#ifndef WRAPPY_H
#define WRAPPY_H

#include <node.h>
#include <v8.h>

using namespace v8;
using namespace node;

class Wrappy: public ObjectWrap {

public:
	static void Init( Handle<Object> target );

private:
	inline Wrappy() {};
	virtual ~Wrappy();

	static Persistent<Function> constructor;
	static Handle<Value> New(const Arguments& args);
	static Handle<Value> Add(const Arguments& args);
public:
	double m_number;
};

#endif