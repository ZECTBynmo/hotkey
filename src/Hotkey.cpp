#include "Hotkey.h"
//////////////////////////////////////////////////////////////////////////////
//
// Hotkey.cpp: Core functionality
// Copyright Mike Vegeto
// 
//////////////////////////////////////////////////////////////////////////////
// DevStudio!namespace Hotkey DevStudio!class Hotkey
#include "Hotkey.h"
#include "v8.h"
using namespace v8;

Persistent<Function> Hotkey::Hotkey::constructor;

//////////////////////////////////////////////////////////////////////////////
/*! Initialize */
Hotkey::Hotkey::Hotkey() :
	m_strHelloWorld("Hello JavaScript Land") {
	
} // end Hotkey::Hotkey()


//////////////////////////////////////////////////////////////////////////////
/*! Initialize our node object */
void Hotkey::Hotkey::Init( v8::Handle<v8::Object> target ) {
	// Prepare constructor template
	Local<FunctionTemplate> functionTemplate = FunctionTemplate::New( Hotkey::New );
	functionTemplate->SetClassName( String::NewSymbol("Hotkey") );
	functionTemplate->InstanceTemplate()->SetInternalFieldCount( 1 );

	// Setup functions here
	functionTemplate->PrototypeTemplate()->Set( String::NewSymbol("getHelloWorldString"), FunctionTemplate::New(Hotkey::getHelloWorldString)->GetFunction() );

	constructor = Persistent<Function>::New( functionTemplate->GetFunction() );
} // end Hotkey::Init()


//////////////////////////////////////////////////////////////////////////////
/*! Create a new instance of the audio engine */
v8::Handle<v8::Value> Hotkey::Hotkey::NewInstance( const v8::Arguments& args ) {
	HandleScope scope;

	unsigned argc = args.Length();

	if( argc > 2 ) 
		argc = 2;

	Handle<Value>* argv = new Handle<Value>[argc];

	argv[0] = args[0];
	if( argc > 1 )
		argv[1] = args[1];

	Local<Object> instance = constructor->NewInstance( argc, argv );

	return scope.Close( instance );
} // end Hotkey::NewInstance()


//////////////////////////////////////////////////////////////////////////////
/*! Create a v8 object */
v8::Handle<v8::Value> Hotkey::Hotkey::New( const v8::Arguments& args ) {
	HandleScope scope;

	Local<Function> callback;
	Local<Object> options;

	Hotkey* pInstance = new Hotkey();
	pInstance->Wrap( args.This() );

	return scope.Close( args.This() );
} // end Hotkey::New()


//////////////////////////////////////////////////////////////////////////////
/*! Returns a the contents of the class' hello world string */
v8::Handle<v8::Value> Hotkey::Hotkey::getHelloWorldString( const v8::Arguments& args ) {
	HandleScope scope;

	Hotkey* pEngine = Hotkey::Unwrap<Hotkey>( args.This() );

	return scope.Close( String::New(pEngine->m_strHelloWorld.c_str()) );
} // end Hotkey::getHelloWorldString()
