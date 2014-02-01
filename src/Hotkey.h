//////////////////////////////////////////////////////////////////////////////
//
// Hotkey.cpp: Core audio functionality
// Copyright Mike Vegeto
// 
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include <v8.h>
#include "node_object_wrap.h"
#include <string>

namespace Hotkey {

	//////////////////////////////////////////////////////////////////////////
	//! Core functionality
	class Hotkey : public node::ObjectWrap {
	public:
		Hotkey();	//!< Initialize

		//! Initialize our node object
        static void Init( v8::Handle<v8::Object> target );
		//! Create a new instance of the audio engine
        static v8::Handle<v8::Value> NewInstance( const v8::Arguments& args );

    private:
        static v8::Persistent<v8::Function> constructor;                
        static v8::Handle<v8::Value> New( const v8::Arguments& args );	//!< Create a v8 object

		//! Returns a the contents of the class' hello world string
		static v8::Handle<v8::Value> getHelloWorldString( const v8::Arguments& args );

		std::string m_strHelloWorld; // Our hello world string, to prove we have access to member vars
	};

} // end namespace Hotkey