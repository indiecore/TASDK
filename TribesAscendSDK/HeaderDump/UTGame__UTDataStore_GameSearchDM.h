#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTDataStore_GameSearchDM." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTDataStore_GameSearchDM." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTDataStore_GameSearchDM." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTDataStore_GameSearchDM : public UDKDataStore_GameSearchBase
	{
	public:
			ADD_OBJECT( UTDataStore_GameSearchHistory, HistoryGameSearchDataStore )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
