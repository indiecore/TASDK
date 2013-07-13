#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_Equip." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_Equip." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_Equip." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_Equip : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bReticulesOpen, 0x2 )
			ADD_VAR( ::BoolProperty, bUpgradePurchase, 0x1 )
			ADD_VAR( ::IntProperty, ReticuleIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PurchasingUpgrade, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PurchasingEquip, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FocusedEquip, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ViewedEquip, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GoldPrice, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, xpPrice, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
