#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.OnlinePlaylistManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.OnlinePlaylistManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.OnlinePlaylistManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlinePlaylistManager : public Object
	{
	public:
			void OnPlaylistPopulationDataUpdated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.OnPlaylistPopulationDataUpdated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadPlaylistComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.OnReadPlaylistComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

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
			void DownloadPlaylist(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.DownloadPlaylist" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetermineFilesToDownload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.DetermineFilesToDownload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadTitleFileComplete( bool bWasSuccessful, ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.OnReadTitleFileComplete" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bWasSuccessful;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinalizePlaylistObjects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.FinalizePlaylistObjects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class OnlineGameSettings* GetGameSettings( int PlaylistId, int GameSettingsId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.GetGameSettings" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PlaylistId;
				*( int* )( params + 4 ) = GameSettingsId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSettings** )( params + function->return_val_offset() );
			}

			bool HasAnyGameSettings( int PlaylistId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.HasAnyGameSettings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PlaylistId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PlaylistSupportsDedicatedServers( int PlaylistId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.PlaylistSupportsDedicatedServers" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PlaylistId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetTeamInfoFromPlaylist( int PlaylistId, int &TeamSize, int &TeamCount, int &MaxPartySize )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.GetTeamInfoFromPlaylist" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = PlaylistId;
				*( int* )( params + 4 ) = TeamSize;
				*( int* )( params + 8 ) = TeamCount;
				*( int* )( params + 12 ) = MaxPartySize;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				TeamSize = *( int* )( params + 4 );
				TeamCount = *( int* )( params + 8 );
				MaxPartySize = *( int* )( params + 12 );
			}

			void GetLoadBalanceIdFromPlaylist( int PlaylistId, int &LoadBalanceId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.GetLoadBalanceIdFromPlaylist" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PlaylistId;
				*( int* )( params + 4 ) = LoadBalanceId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				LoadBalanceId = *( int* )( params + 4 );
			}

			bool IsPlaylistArbitrated( int PlaylistId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.IsPlaylistArbitrated" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PlaylistId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetUrlFromPlaylist( int PlaylistId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.GetUrlFromPlaylist" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PlaylistId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void GetMapCycleFromPlaylist( int PlaylistId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.GetMapCycleFromPlaylist" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = PlaylistId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* GetInventorySwapFromPlaylist( int PlaylistId, ScriptClass* SourceInventory )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.GetInventorySwapFromPlaylist" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PlaylistId;
				*( ScriptClass** )( params + 4 ) = SourceInventory;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void GetContentIdsFromPlaylist( int PlaylistId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.GetContentIdsFromPlaylist" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = PlaylistId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReadPlaylistPopulation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.ReadPlaylistPopulation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadPlaylistPopulationComplete( bool bWasSuccessful, ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.OnReadPlaylistPopulationComplete" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bWasSuccessful;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ParsePlaylistPopulationData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.ParsePlaylistPopulationData" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPopulationInfoFromPlaylist( int PlaylistId, int &WorldwideTotal, int &RegionTotal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.GetPopulationInfoFromPlaylist" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = PlaylistId;
				*( int* )( params + 4 ) = WorldwideTotal;
				*( int* )( params + 8 ) = RegionTotal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				WorldwideTotal = *( int* )( params + 4 );
				RegionTotal = *( int* )( params + 8 );
			}

			void SendPlaylistPopulationUpdate( int NumPlayers )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.SendPlaylistPopulationUpdate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = NumPlayers;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReadDataCenterId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.ReadDataCenterId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadDataCenterIdComplete( bool bWasSuccessful, ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.OnReadDataCenterIdComplete" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bWasSuccessful;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ParseDataCenterId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlinePlaylistManager.ParseDataCenterId" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
