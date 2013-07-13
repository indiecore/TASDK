#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InventoryManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InventoryManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InventoryManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InventoryManager : public Actor
	{
	public:
			ADD_VAR( ::BoolProperty, bMustHoldWeapon, 0x1 )
			ADD_OBJECT( Weapon, LastAttemptedSwitchToWeapon )
			ADD_OBJECT( Weapon, PendingWeapon )
			ADD_OBJECT( Inventory, InventoryChain )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
