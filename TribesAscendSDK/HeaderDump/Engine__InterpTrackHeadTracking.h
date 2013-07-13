#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InterpTrackHeadTracking." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InterpTrackHeadTracking." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InterpTrackHeadTracking." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpTrackHeadTracking : public InterpTrack
	{
	public:
			ADD_VAR( ::FloatProperty, MaxInterestTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinLookAtTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxLookAtTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLookAtPawns, 0x2 )
			ADD_VAR( ::BoolProperty, bDisableBeyondLimit, 0x1 )
			ADD_VAR( ::FloatProperty, LookAtActorRadius, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
