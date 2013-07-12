#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " IpDrv.OnlinePlaylistManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty IpDrv.OnlinePlaylistManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty IpDrv.OnlinePlaylistManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlinePlaylistManager : public Object
	{
	public:
			ADD_VAR( ::StrProperty, DataCenterFileName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DataCenterId, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, EventsInterfaceName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentPlaylistId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinPlaylistIdToReport, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PlaylistPopulationUpdateInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NextPlaylistPopulationUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PopulationFileName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RegionTotalPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, WorldwideTotalPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VersionNumber, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SuccessfulCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DownloadCount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
