#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTSeqCond_HasInventory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTSeqCond_HasInventory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTSeqCond_HasInventory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSeqCond_HasInventory : public SequenceCondition
	{
	public:
			ADD_VAR( ::BoolProperty, bCheckVehicleDriver, 0x2 )
			ADD_VAR( ::BoolProperty, bAllowSubclass, 0x1 )
			ADD_OBJECT( Actor, Target )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
