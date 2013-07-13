#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_ServerTime." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_ServerTime." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_ServerTime." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_ServerTime : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bBoundsPopup, 0x10 )
			ADD_VAR( ::BoolProperty, bRespawnTimePopup, 0x8 )
			ADD_VAR( ::BoolProperty, bOverTimeLimitPopup, 0x4 )
			ADD_VAR( ::BoolProperty, bTimeLimitPopup, 0x2 )
			ADD_VAR( ::BoolProperty, bWarmupTimePopup, 0x1 )
			ADD_VAR( ::IntProperty, MaxBOunds, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinBounds, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
