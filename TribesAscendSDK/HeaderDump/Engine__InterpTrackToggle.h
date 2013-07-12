#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.InterpTrackToggle." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.InterpTrackToggle." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.InterpTrackToggle." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpTrackToggle : public InterpTrack
	{
	public:
			ADD_VAR( ::BoolProperty, bFireEventsWhenJumpingForwards, 0x10 )
			ADD_VAR( ::BoolProperty, bFireEventsWhenBackwards, 0x8 )
			ADD_VAR( ::BoolProperty, bFireEventsWhenForwards, 0x4 )
			ADD_VAR( ::BoolProperty, bActivateWithJustAttachedFlag, 0x2 )
			ADD_VAR( ::BoolProperty, bActivateSystemEachUpdate, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
