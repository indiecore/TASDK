#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_ClanTagChange." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_ClanTagChange." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_ClanTagChange." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_ClanTagChange : public GFxTrPage_VendorTable
	{
	public:
			ADD_VAR( ::StrProperty, RemovePopupTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ChangePopupTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RemovePopupBody, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ChangePopupBody, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RemoveItem, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ChangeItem, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, xpPrice, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, gpPrice, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrencyNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConfirmNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EntryNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PopupNum, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
