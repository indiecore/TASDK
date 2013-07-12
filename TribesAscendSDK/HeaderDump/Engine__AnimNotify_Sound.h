#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AnimNotify_Sound." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AnimNotify_Sound." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AnimNotify_Sound." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNotify_Sound : public AnimNotify
	{
	public:
			ADD_VAR( ::FloatProperty, PitchMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VolumeMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PercentToPlay, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIgnoreIfActorHidden, 0x2 )
			ADD_VAR( ::BoolProperty, bFollowActor, 0x1 )
			ADD_OBJECT( SoundCue, SoundCue )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
