#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineStatsInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineStatsInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineStatsInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineStatsInterface : public Interface
	{
	public:
			bool WriteOnlinePlayerScores( ScriptName SessionName, int LeaderboardId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.WriteOnlinePlayerScores" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )params = SessionName;
				*( int* )( params + 8 ) = LeaderboardId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RegisterHostStatGuid( ScriptArray< wchar_t > &HostStatGuid )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.RegisterHostStatGuid" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = HostStatGuid;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				HostStatGuid = *( ScriptArray< wchar_t >* )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetClientStatGuid(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.GetClientStatGuid" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool RegisterStatGuid( void* PlayerID, ScriptArray< wchar_t > &ClientStatGuid )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.RegisterStatGuid" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )params = PlayerID;
				*( ScriptArray< wchar_t >* )( params + 8 ) = ClientStatGuid;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ClientStatGuid = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetHostStatGuid(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.GetHostStatGuid" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool ReadOnlineStats( class OnlineStatsRead* StatsRead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.ReadOnlineStats" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class OnlineStatsRead** )( params + 12 ) = StatsRead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadOnlineStatsForFriends( byte LocalUserNum, class OnlineStatsRead* StatsRead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.ReadOnlineStatsForFriends" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = LocalUserNum;
				*( class OnlineStatsRead** )( params + 4 ) = StatsRead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadOnlineStatsByRank( class OnlineStatsRead* StatsRead, int StartIndex, int NumToRead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.ReadOnlineStatsByRank" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class OnlineStatsRead** )params = StatsRead;
				*( int* )( params + 4 ) = StartIndex;
				*( int* )( params + 8 ) = NumToRead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadOnlineStatsByRankAroundPlayer( byte LocalUserNum, class OnlineStatsRead* StatsRead, int NumRows )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.ReadOnlineStatsByRankAroundPlayer" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = LocalUserNum;
				*( class OnlineStatsRead** )( params + 4 ) = StatsRead;
				*( int* )( params + 8 ) = NumRows;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnReadOnlineStatsComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.OnReadOnlineStatsComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRegisterHostStatGuidComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.OnRegisterHostStatGuidComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFlushOnlineStatsComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.OnFlushOnlineStatsComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddReadOnlineStatsCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.AddReadOnlineStatsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadOnlineStatsCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.ClearReadOnlineStatsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FreeStats( class OnlineStatsRead* StatsRead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.FreeStats" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class OnlineStatsRead** )params = StatsRead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WriteOnlineStats( ScriptName SessionName, void* Player, class OnlineStatsWrite* StatsWrite )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.WriteOnlineStats" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = SessionName;
				*( void** )( params + 8 ) = Player;
				*( class OnlineStatsWrite** )( params + 16 ) = StatsWrite;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FlushOnlineStats( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.FlushOnlineStats" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddFlushOnlineStatsCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.AddFlushOnlineStatsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlushOnlineStatsCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.ClearFlushOnlineStatsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddRegisterHostStatGuidCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.AddRegisterHostStatGuidCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRegisterHostStatGuidCompleteDelegateDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsInterface.ClearRegisterHostStatGuidCompleteDelegateDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
