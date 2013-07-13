#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrChatInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrChatInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrChatInput." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrChatInput : public Interaction
	{
	public:
			ADD_VAR( ::BoolProperty, bEnableUI, 0x4 )
			ADD_VAR( ::BoolProperty, bCtrl, 0x2 )
			ADD_VAR( ::BoolProperty, bCaptureKeyInput, 0x1 )
			ADD_VAR( ::StrProperty, ChannelStr, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TypedStrPos, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TypedStr, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, DefaultTexture_White )
			ADD_OBJECT( Texture2D, DefaultTexture_Black )
			ADD_OBJECT( LocalPlayer, ConsoleTargetPlayer )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
