//////////////////////////////////////////////////////////////////////////
// hotkey - main module
//////////////////////////////////////////////////////////////////////////
//
// Main javascript API
/* ----------------------------------------------------------------------
													Object Structures
-------------------------------------------------------------------------
	
*/

//////////////////////////////////////////////////////////////////////////
// Namespace (lol)
var SHOW_DEBUG_PRINTS = true;																		
var log = function(a) { if(SHOW_DEBUG_PRINTS) console.log(a); };	// A log function we can turn off

var MyNativeExtension = require( __dirname + "/build/Release/Hotkey" );


//////////////////////////////////////////////////////////////////////////
// Constructor
function Hotkey() {
	this.native = MyNativeExtension.Hotkey(); // Instantiate our native extension

	return this;
} // end Hotkey();


//////////////////////////////////////////////////////////////////////////
// Returns our main audio processing function
Hotkey.prototype.getHelloWorldString = function() {
	return this.native.getHelloWorldString();
} // end Hotkey.getHelloWorldString()


exports.hotkey = Hotkey;