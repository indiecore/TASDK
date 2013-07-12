#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_ToggleConstraintDrive." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_ToggleConstraintDrive." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_ToggleConstraintDrive." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_ToggleConstraintDrive : public SequenceAction
	{
	public:
			ADD_VAR( ::BoolProperty, bEnableLinearPositionDrive, 0x4 )
			ADD_VAR( ::BoolProperty, bEnableLinearvelocityDrive, 0x8 )
			ADD_VAR( ::BoolProperty, bEnableAngularPositionDrive, 0x1 )
			ADD_VAR( ::BoolProperty, bEnableAngularVelocityDrive, 0x2 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
