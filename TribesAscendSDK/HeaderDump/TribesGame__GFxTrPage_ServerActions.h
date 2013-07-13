#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_ServerActions." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_ServerActions." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_ServerActions." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_ServerActions : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bPopup, 0x1 )
			ADD_VAR( ::IntProperty, PopupNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BanPlayerNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, KickPlayerNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GotoMapServerNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, KillServerNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DisableServerNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EnableServerNum, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
