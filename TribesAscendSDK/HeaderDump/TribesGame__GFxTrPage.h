#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrPage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrPage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrPage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage : public GFxObject
	{
	public:
			ADD_VAR( ::StrProperty, HelpButtonYLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonXLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonBLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonALabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonYKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonXKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonBKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpButtonAKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PageLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PageLabelOverride, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowTribesLogo, 0x200 )
			ADD_VAR( ::BoolProperty, bParentLocked, 0x100 )
			ADD_VAR( ::BoolProperty, bHasModifiers, 0x80 )
			ADD_VAR( ::BoolProperty, bCreated, 0x40 )
			ADD_VAR( ::BoolProperty, bActive, 0x20 )
			ADD_VAR( ::BoolProperty, bAllowBack, 0x10 )
			ADD_VAR( ::BoolProperty, bEndOfLine, 0x8 )
			ADD_VAR( ::BoolProperty, bRemoveOption, 0x4 )
			ADD_VAR( ::BoolProperty, bModifyOption, 0x2 )
			ADD_VAR( ::BoolProperty, bFillingFocus, 0x1 )
			ADD_VAR( ::IntProperty, LoadoutEquipType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LoadoutClassId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NewAction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OptionCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ActiveIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ScrollIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HelpButtonYNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HelpButtonXNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HelpButtonBNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HelpButtonANum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GoBack, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ActiveLoadout, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
