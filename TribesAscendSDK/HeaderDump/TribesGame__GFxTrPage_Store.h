#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_Store." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_Store." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_Store." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_Store : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, PromoPopupTitle, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ClaimPromotionAction, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NoNameChangeInGame, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWaitingForClaimPromoPopup, 0x10 )
			ADD_VAR( ::BoolProperty, bConfirmationPopup, 0x8 )
			ADD_VAR( ::BoolProperty, bClassRequiredPopup, 0x4 )
			ADD_VAR( ::BoolProperty, bSelectionPopup, 0x2 )
			ADD_VAR( ::BoolProperty, bCurrencyPopup, 0x1 )
			ADD_VAR( ::IntProperty, classIdRequired, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PopupNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumGold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumDeal, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HZCost, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, xpCost, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
