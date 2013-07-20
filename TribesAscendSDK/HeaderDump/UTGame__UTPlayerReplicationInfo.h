#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTPlayerReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTPlayerReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTPlayerReplicationInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTPlayerReplicationInfo : public PlayerReplicationInfo
	{
	public:
			ADD_OBJECT( ScriptClass, CharClassInfo )
			ADD_VAR( ::BoolProperty, bHasFlag, 0x1 )
			ADD_OBJECT( ScriptClass, VoiceClass )
			int IncrementEventStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.IncrementEventStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class UTCarriedObject* GetFlag(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.GetFlag" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTCarriedObject** )( params + function->return_val_offset() );
			}

			int IncrementPickupStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.IncrementPickupStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bIsFemale, 0x4 )
			ADD_OBJECT( Texture, CharPortrait )
			int IncrementVehicleKillStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.IncrementVehicleKillStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTPlayerReplicationInfo, LastKillerPRI )
			int IncrementSuicideStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.IncrementSuicideStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int IncrementKillStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.IncrementKillStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int IncrementDeathStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.IncrementDeathStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, spree, 0xFFFFFFFF )
			ScriptArray< wchar_t > GetCallSign(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.GetCallSign" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTSquadAI, Squad )
			ADD_VAR( ::BoolProperty, bHolding, 0x2 )
			ADD_VAR( ::IntProperty, MultiKillLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastKillTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, OrdersIndex, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OrdersString, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, HUDLocation, 0xFFFFFFFF )
			ADD_OBJECT( UTCarriedObject, HasFlag )
			bool IsLocalPlayerPRI(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.IsLocalPlayerPRI" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldBroadCastWelcomeMessage( bool bExiting )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.ShouldBroadCastWelcomeMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bExiting;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StartDrivingStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.StartDrivingStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopDrivingStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.StopDrivingStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartPowerupTimeStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.StartPowerupTimeStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopPowerupTimeStat( ScriptName NewStatName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.StopPowerupTimeStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewStatName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFlag( class UTCarriedObject* NewFlag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.SetFlag" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTCarriedObject** )params = NewFlag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementKills( bool bEnemyKill )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.IncrementKills" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnemyKill;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OverrideWith( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.OverrideWith" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CopyProperties( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.CopyProperties" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeamlessTravelTo( class PlayerReplicationInfo* NewPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.SeamlessTravelTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = NewPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowClientToTeleport( class Actor* DestinationActor, class UTPawn* &OwnerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.AllowClientToTeleport" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = DestinationActor;
				*( class UTPawn** )( params + 4 ) = OwnerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OwnerPawn = *( class UTPawn** )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerTeleportToActor( class Actor* DestinationActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.ServerTeleportToActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = DestinationActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowMidGameMenu( bool bInitial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.ShowMidGameMenu" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInitial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AttemptMidGameMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPlayerReplicationInfo.AttemptMidGameMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
