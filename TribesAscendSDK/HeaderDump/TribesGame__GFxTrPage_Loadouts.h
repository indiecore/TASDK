#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrPage_Loadouts." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrPage_Loadouts." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrPage_Loadouts." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_Loadouts : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bInSelection, 0x1 )
			ADD_VAR( ::BoolProperty, bClassLocked, 0x2 )
			ADD_VAR( ::StrProperty, LoadoutClassName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bConfirmationPopup, 0x10 )
			ADD_VAR( ::BoolProperty, bSelectionPopup, 0x8 )
			ADD_VAR( ::BoolProperty, bCurrencyPopup, 0x4 )
			ADD_VAR( ::IntProperty, ModelEquip, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PopupNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, XPAmount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GPAmount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
