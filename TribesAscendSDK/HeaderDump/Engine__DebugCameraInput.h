#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DebugCameraInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DebugCameraInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DebugCameraInput." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DebugCameraInput : public PlayerInput
	{
	public:
			bool InputKey( int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DebugCameraInput.InputKey" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( int* )params = ControllerId;
				*( ScriptName* )( params + 4 ) = Key;
				*( byte* )( params + 12 ) = Event;
				*( float* )( params + 16 ) = AmountDepressed;
				*( bool* )( params + 20 ) = bGamepad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
