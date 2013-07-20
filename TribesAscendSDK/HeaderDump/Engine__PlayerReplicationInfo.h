#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PlayerReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PlayerReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PlayerReplicationInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PlayerReplicationInfo : public ReplicationInfo
	{
	public:
			ADD_VAR( ::BoolProperty, bAdmin, 0x1 )
			ADD_VAR( ::StrProperty, PlayerName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerID, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOnlySpectator, 0x4 )
			ADD_OBJECT( TeamInfo, Team )
			ADD_VAR( ::NameProperty, SessionName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExactPing, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Ping, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsSpectator, 0x2 )
			ADD_VAR( ::BoolProperty, bReadyToPlay, 0x10 )
			ADD_VAR( ::BoolProperty, bOutOfLives, 0x20 )
			ADD_VAR( ::FloatProperty, Score, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StartTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SavedNetworkAddress, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWaitingPlayer, 0x8 )
			ADD_VAR( ::IntProperty, Kills, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bFromPreviousLevel, 0x200 )
			class PlayerReplicationInfo* Duplicate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.Duplicate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerReplicationInfo** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bIsInactive, 0x100 )
			ADD_VAR( ::StrProperty, OldName, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, Avatar )
			ADD_VAR( ::IntProperty, StatAvgOutBPS, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatMaxOutBPS, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatAvgInBPS, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatMaxInBPS, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatPKLMax, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatPKLMin, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatPKLTotal, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatPingMax, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatPingMin, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatPingTotals, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StatConnectionCounts, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, GameMessageClass )
			ADD_VAR( ::StrProperty, StringUnknown, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, StringSpectating, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHasBeenWelcomed, 0x80 )
			ADD_VAR( ::BoolProperty, bBot, 0x40 )
			ADD_VAR( ::IntProperty, NumLives, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, TTSSpeaker, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Deaths, 0xFFFFFFFF )
			void UpdatePing( float TimeStamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.UpdatePing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = TimeStamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientInitialize( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.ClientInitialize" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPlayerTeam( class TeamInfo* NewTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.SetPlayerTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TeamInfo** )params = NewTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldBroadCastWelcomeMessage( bool bExiting )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.ShouldBroadCastWelcomeMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bExiting;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetHumanReadableName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.GetHumanReadableName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void DisplayDebug( class HUD* HUD, float &YL, float &YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = YL;
				*( float* )( params + 8 ) = YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				YL = *( float* )( params + 4 );
				YPos = *( float* )( params + 8 );
			}

			void SetPlayerName( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.SetPlayerName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetWaitingPlayer( bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.SetWaitingPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OverrideWith( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.OverrideWith" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CopyProperties( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.CopyProperties" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementDeaths( int Amt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.IncrementDeaths" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeamlessTravelTo( class PlayerReplicationInfo* NewPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.SeamlessTravelTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = NewPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetUniqueId( void* PlayerUniqueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.SetUniqueId" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerUniqueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.GetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool IsInvalidName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.IsInvalidName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RegisterPlayerWithSession(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.RegisterPlayerWithSession" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnregisterPlayerFromSession(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.UnregisterPlayerFromSession" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetSpectatorName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerReplicationInfo.GetSpectatorName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
