#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Console." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Console." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Console." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Console : public Interaction
	{
	public:
			ADD_VAR( ::IntProperty, AutoCompleteIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TypedStrPos, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TypedStr, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsRuntimeAutoCompleteUpToDate, 0x40 )
			ADD_VAR( ::BoolProperty, bRequireCtrlToNavigateAutoComplete, 0x20 )
			ADD_VAR( ::BoolProperty, bAutoCompleteLocked, 0x10 )
			ADD_VAR( ::BoolProperty, bEnableUI, 0x8 )
			ADD_VAR( ::BoolProperty, bCtrl, 0x4 )
			ADD_VAR( ::BoolProperty, bCaptureKeyInput, 0x2 )
			ADD_VAR( ::BoolProperty, bNavigatingHistory, 0x1 )
			ADD_VAR( ::StrProperty, History, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HistoryCur, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HistoryBot, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HistoryTop, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SBPos, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SBHead, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxScrollbackSize, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, TypeKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ConsoleKey, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, DefaultTexture_White )
			ADD_OBJECT( Texture2D, DefaultTexture_Black )
			ADD_OBJECT( LocalPlayer, ConsoleTargetPlayer )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
