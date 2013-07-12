#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrPage_Main." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrPage_Main." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrPage_Main." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_Main : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bSwingingCamera, 0x1 )
			ADD_VAR( ::StrProperty, TabOffset, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, QueueTimer, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAnimInit, 0x2 )
			ADD_VAR( ::IntProperty, FeatureSwapTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FeatureShowTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ActiveFeature, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GoldDealId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumQuit, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
