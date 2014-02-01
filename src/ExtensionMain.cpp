//////////////////////////////////////////////////////////////////////////////
//
// ExtensionMain.cpp : Main module source, declares all exports
// Copyright Mike Vegeto
// 
//////////////////////////////////////////////////////////////////////////////

#include <v8.h>
//#pragma comment(lib, "node")
#include <node.h>

#include "Hotkey.h"
#include <string>
#include <stdio.h>
using namespace v8;

Handle<Value> CreateInstance(const Arguments& args) {
    HandleScope scope;
    return scope.Close( Hotkey::Hotkey::NewInstance(args) );
} // end CreateInstance()

void InitAll(Handle<Object> target) {
    Hotkey::Hotkey::Init( target );

    target->Set( String::NewSymbol("Hotkey"), FunctionTemplate::New(CreateInstance)->GetFunction() );
} // end InitAll()

NODE_MODULE( Hotkey, InitAll );
