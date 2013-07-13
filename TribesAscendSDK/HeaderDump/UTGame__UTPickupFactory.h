#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTPickupFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTPickupFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTPickupFactory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTPickupFactory : public UDKPickupFactory
	{
	public:
			ADD_OBJECT( ForceFeedbackWaveform, PickUpWaveForm )
			ADD_VAR( ::FloatProperty, LastSeekNotificationTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHasLocationSpeech, 0x1 )
			ADD_VAR( ::NameProperty, PickupStatName, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, RespawnSound )
			ADD_OBJECT( Controller, TeamOwner )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
