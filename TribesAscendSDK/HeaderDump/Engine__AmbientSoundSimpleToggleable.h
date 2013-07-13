#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AmbientSoundSimpleToggleable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AmbientSoundSimpleToggleable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AmbientSoundSimpleToggleable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AmbientSoundSimpleToggleable : public AmbientSoundSimple
	{
	public:
			ADD_VAR( ::FloatProperty, FadeOutVolumeLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeOutDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeInVolumeLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeInDuration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIgnoreAutoPlay, 0x4 )
			ADD_VAR( ::BoolProperty, bFadeOnToggle, 0x2 )
			ADD_VAR( ::BoolProperty, bCurrentlyPlaying, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
