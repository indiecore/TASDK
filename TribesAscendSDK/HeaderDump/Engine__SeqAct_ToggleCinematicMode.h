#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_ToggleCinematicMode." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_ToggleCinematicMode." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_ToggleCinematicMode." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_ToggleCinematicMode : public SequenceAction
	{
	public:
			ADD_VAR( ::BoolProperty, bHidePlayer, 0x4 )
			ADD_VAR( ::BoolProperty, bHideHUD, 0x10 )
			ADD_VAR( ::BoolProperty, bDisableMovement, 0x1 )
			ADD_VAR( ::BoolProperty, bDisableTurning, 0x2 )
			ADD_VAR( ::BoolProperty, bDisableInput, 0x8 )
			ADD_VAR( ::BoolProperty, bDroppedPickups, 0x40 )
			ADD_VAR( ::BoolProperty, bDeadBodies, 0x20 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
