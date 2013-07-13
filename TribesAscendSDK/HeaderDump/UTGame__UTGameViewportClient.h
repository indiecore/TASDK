#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTGameViewportClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTGameViewportClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTGameViewportClient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGameViewportClient : public UDKGameViewportClient
	{
	public:
			ADD_VAR( ::StrProperty, LevelActionMessages, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ProgressMessageSceneClassName, 0xFFFFFFFF )
			ADD_OBJECT( Font, LoadingScreenHintMessageFont )
			ADD_OBJECT( Font, LoadingScreenGameTypeNameFont )
			ADD_OBJECT( Font, LoadingScreenMapNameFont )
			ADD_VAR( ::StrProperty, UTFrontEndString, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
