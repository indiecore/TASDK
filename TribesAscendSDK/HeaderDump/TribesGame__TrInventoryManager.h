#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrInventoryManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrInventoryManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrInventoryManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrInventoryManager : public UTInventoryManager
	{
	public:
			ADD_VAR( ::BoolProperty, c_bRetryEquippingPrimaryWeapon, 0x1 )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_VAR( ::ByteProperty, m_PreviousDeviceEquipPoint, 0xFFFFFFFF )
			ADD_OBJECT( TrDevice, m_RealLastDevice )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
