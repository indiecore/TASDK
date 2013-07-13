#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrSettingsManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrSettingsManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrSettingsManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSettingsManager : public Object
	{
	public:
			ADD_OBJECT( TrRegionSettings, RegionSettings )
			ADD_OBJECT( TrAudioSettings, AudioSettings )
			ADD_OBJECT( TrControlSettings, ControlSettings )
			ADD_OBJECT( TrKeyBindings, KeyBindings )
			ADD_OBJECT( TrHUDSettings, HUDSettings )
			ADD_OBJECT( TrVideoSettings, VideoSettings )
			ADD_OBJECT( GFxTrMenuMoviePlayer, MP )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
