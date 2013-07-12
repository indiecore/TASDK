#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTSeqCond_IsUsingWeapon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTSeqCond_IsUsingWeapon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTSeqCond_IsUsingWeapon." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSeqCond_IsUsingWeapon : public SequenceCondition
	{
	public:
			ADD_VAR( ::BoolProperty, bMustBeImpactHammer, 0x2 )
			ADD_VAR( ::BoolProperty, bAllowSubclass, 0x1 )
			ADD_OBJECT( Actor, Target )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
