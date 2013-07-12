#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SoundCue." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SoundCue." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SoundCue." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SoundCue : public Object
	{
	public:
			ADD_VAR( ::StrProperty, FaceFXAnimName, 0xFFFFFFFF )
			ADD_OBJECT( FaceFXAnimSet, FaceFXAnimSetRef )
			ADD_VAR( ::StrProperty, FaceFXGroupName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SoundGroup, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentPlayCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxConcurrentPlayCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Duration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PitchMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VolumeMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxAudibleDistance, 0xFFFFFFFF )
			ADD_OBJECT( SoundNode, FirstNode )
			ADD_VAR( ::ByteProperty, SoundClassName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SoundClass, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
