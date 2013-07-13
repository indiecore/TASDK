#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InterpTrack." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InterpTrack." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InterpTrack." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpTrack : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bIsCollapsed, 0x100 )
			ADD_VAR( ::BoolProperty, bIsRecording, 0x80 )
			ADD_VAR( ::BoolProperty, bIsSelected, 0x40 )
			ADD_VAR( ::BoolProperty, bVisible, 0x20 )
			ADD_VAR( ::BoolProperty, bSubTrackOnly, 0x10 )
			ADD_VAR( ::BoolProperty, bIsAnimControlTrack, 0x8 )
			ADD_VAR( ::BoolProperty, bDisableTrack, 0x4 )
			ADD_VAR( ::BoolProperty, bDirGroupOnly, 0x2 )
			ADD_VAR( ::BoolProperty, bOnePerGroup, 0x1 )
			ADD_VAR( ::StrProperty, TrackTitle, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ActiveCondition, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
