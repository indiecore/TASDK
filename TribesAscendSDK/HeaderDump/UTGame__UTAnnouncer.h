#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTAnnouncer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTAnnouncer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTAnnouncer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTAnnouncer : public Info
	{
	public:
			ADD_VAR( ::StrProperty, UTVoiceSoundCueSoundCue, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, UTVoiceSoundCue )
			ADD_VAR( ::StrProperty, CustomAnnouncerSoundCue, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, AnnouncerSoundCue )
			ADD_OBJECT( UTPlayerController, PlayerOwner )
			ADD_OBJECT( UTQueuedAnnouncement, Queue )
			ADD_VAR( ::IntProperty, PlayingAnnouncementIndex, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AnnouncerLevel, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
