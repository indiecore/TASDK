#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrEmitCameraEffect_Speed." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrEmitCameraEffect_Speed." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrEmitCameraEffect_Speed." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrEmitCameraEffect_Speed : public UDKEmitCameraEffect
	{
	public:
			ADD_VAR( ::FloatProperty, m_fFadeOutWeatherSoundTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFadeInWeatherSoundTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_WeatherSound )
			ADD_VAR( ::BoolProperty, m_bUpdateLocationBasedOnVelocity, 0x2 )
			ADD_VAR( ::BoolProperty, m_bUpdateRotation, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
