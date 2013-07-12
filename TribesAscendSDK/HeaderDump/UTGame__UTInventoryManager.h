#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTInventoryManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTInventoryManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTInventoryManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTInventoryManager : public InventoryManager
	{
	public:
			ADD_VAR( ::BoolProperty, bInfiniteAmmo, 0x1 )
			ADD_VAR( ::FloatProperty, LastAdjustWeaponTime, 0xFFFFFFFF )
			ADD_OBJECT( UTWeapon, PendingSwitchWeapon )
			ADD_OBJECT( Weapon, PreviousWeapon )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
