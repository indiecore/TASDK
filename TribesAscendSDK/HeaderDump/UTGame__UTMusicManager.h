#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTMusicManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTMusicManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTMusicManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTMusicManager : public Info
	{
	public:
			ADD_VAR( ::FloatProperty, MusicStartTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastBeat, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentState, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MusicVolume, 0xFFFFFFFF )
			ADD_OBJECT( UTPlayerController, PlayerOwner )
			ADD_VAR( ::FloatProperty, CurrTempo, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrFadeFactor, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PendingEvent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PendingEventPlayTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PendingEventDelay, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPendingAction, 0x1 )
			ADD_VAR( ::FloatProperty, LastActionEventTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StingerVolumeMultiplier, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
