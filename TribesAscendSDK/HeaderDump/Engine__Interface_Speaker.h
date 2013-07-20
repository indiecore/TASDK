#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Interface_Speaker." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Interface_Speaker." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Interface_Speaker." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Interface_Speaker : public Interface
	{
	public:
			void Speak( class SoundCue* Cue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Interface_Speaker.Speak" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SoundCue** )params = Cue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
