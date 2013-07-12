#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.HUD." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.HUD." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.HUD." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class HUD : public Actor
	{
	public:
			ADD_OBJECT( Canvas, Canvas )
			ADD_VAR( ::FloatProperty, RatioY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RatioX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CenterY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CenterX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SizeX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RenderDelta, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHUDRenderTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConsoleMessagePosY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConsoleMessagePosX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxHUDAreaMessageCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MessageFontOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConsoleFontSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConsoleMessageCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HudCanvasScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowOverlays, 0x40 )
			ADD_VAR( ::BoolProperty, bMessageBeep, 0x20 )
			ADD_VAR( ::BoolProperty, bShowBadConnectionAlert, 0x10 )
			ADD_VAR( ::BoolProperty, bShowDebugInfo, 0x8 )
			ADD_VAR( ::BoolProperty, bShowScores, 0x4 )
			ADD_VAR( ::BoolProperty, bShowHUD, 0x2 )
			ADD_VAR( ::BoolProperty, bLostFocusPaused, 0x1 )
			ADD_OBJECT( PlayerController, PlayerOwner )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
