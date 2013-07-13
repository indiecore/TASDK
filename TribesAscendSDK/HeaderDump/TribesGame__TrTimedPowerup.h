#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrTimedPowerup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrTimedPowerup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrTimedPowerup." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrTimedPowerup : public TrInventory
	{
	public:
			ADD_VAR( ::FloatProperty, PP_Scene_Desaturation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PP_Scene_HighLights, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WarningTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransitionDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransitionTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PowerupStatName, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, PowerupOverSound )
			ADD_VAR( ::IntProperty, HudIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeRemaining, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
