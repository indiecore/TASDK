#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_ServerTeam." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_ServerTeam." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_ServerTeam." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_ServerTeam : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bBoundsPopup, 0x8 )
			ADD_VAR( ::BoolProperty, bPopupBaseDestPopup, 0x4 )
			ADD_VAR( ::BoolProperty, bDisparityPopup, 0x2 )
			ADD_VAR( ::BoolProperty, bMaxPlayerPopup, 0x1 )
			ADD_VAR( ::IntProperty, MaxBOunds, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinBounds, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
