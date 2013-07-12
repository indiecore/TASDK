#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.GameViewportClient." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.GameViewportClient." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.GameViewportClient." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameViewportClient : public Object
	{
	public:
			ADD_OBJECT( Console, ViewportConsole )
			ADD_OBJECT( UIInteraction, UIController )
			ADD_VAR( ::ByteProperty, ActiveSplitscreenType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, DesiredSplitscreenType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDebugNoGFxUI, 0x80 )
			ADD_VAR( ::ByteProperty, Default2PSplitType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Default3PSplitType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowTitleSafeZone, 0x1 )
			ADD_VAR( ::FloatProperty, ProgressTimeOut, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ProgressFadeTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ProgressMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, LoadingMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SavingMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ConnectingMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PrecachingMessage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PausedMessage, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDisplayingUIMouseCursor, 0x2 )
			ADD_VAR( ::BoolProperty, bUIMouseCaptureOverride, 0x4 )
			ADD_VAR( ::BoolProperty, bOverrideDiffuseAndSpecular, 0x8 )
			ADD_VAR( ::BoolProperty, bIsPlayInEditorViewport, 0x10 )
			ADD_VAR( ::BoolProperty, bShowSystemMouseCursor, 0x20 )
			ADD_VAR( ::BoolProperty, bDisableWorldRendering, 0x40 )
			ADD_VAR( ::BoolProperty, bUseHardwareCursorWhenWindowed, 0x100 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
