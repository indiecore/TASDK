#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AmbientSoundSimple." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AmbientSoundSimple." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AmbientSoundSimple." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AmbientSoundSimple : public AmbientSound
	{
	public:
			ADD_OBJECT( SoundNodeAmbient, SoundNodeInstance )
			ADD_OBJECT( SoundCue, SoundCueInstance )
			ADD_OBJECT( SoundNodeAmbient, AmbientProperties )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
