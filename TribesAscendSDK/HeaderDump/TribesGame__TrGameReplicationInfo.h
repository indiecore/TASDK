#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGameReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGameReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGameReplicationInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGameReplicationInfo : public UTGameReplicationInfo
	{
	public:
			bool IsClassAllowed( int TeamNum, ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.IsClassAllowed" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = TeamNum;
				*( ScriptClass** )( params + 4 ) = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrServerSettingsInfo, r_ServerConfig )
			int GetTeamSize( byte TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.GetTeamSize" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool CanJoinTeam( byte RequestedTeam, byte CurrentTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.CanJoinTeam" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = RequestedTeam;
				*( byte* )( params + 1 ) = CurrentTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrPlayerReplicationInfo, r_BEPlayerList )
			ADD_OBJECT( TrPlayerReplicationInfo, r_DSPlayerList )
			ADD_VAR( ::IntProperty, r_nRoundScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nCurrentRound, 0xFFFFFFFF )
			ADD_OBJECT( TrObjectPool, m_TrObjectPool )
			float GetGlobalSpeedCapMultiplier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.GetGlobalSpeedCapMultiplier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetGlobalAccelerationMultiplier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.GetGlobalAccelerationMultiplier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetGlobalAirSpeedMultiplier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.GetGlobalAirSpeedMultiplier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetGlobalMaxJetpackThrustSpeedMultiplier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.GetGlobalMaxJetpackThrustSpeedMultiplier" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, r_PhysType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrentSensorBlipOpacity, 0xFFFFFFFF )
			ADD_OBJECT( TrFlagBase, m_Flags )
			ADD_VAR( ::BoolProperty, r_bSkiEnabled, 0x10 )
			ADD_VAR( ::IntProperty, r_nNumCapturePointsHeld, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GeneratorPower, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bPoweredCallins, 0x2 )
			ADD_OBJECT( PlayerReplicationInfo, m_CurrentRabbitPRI )
			ADD_OBJECT( TrDaDCore, r_DaDCore )
			ADD_OBJECT( TrDaDCapacitor, r_DaDCapacitorBE )
			ADD_OBJECT( TrDaDCapacitor, r_DaDCapacitorDS )
			ADD_VAR( ::IntProperty, FlagReturnTime, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, m_RabbitLeaderBoard )
			ADD_VAR( ::IntProperty, r_CarrierCoreHealth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_CarrierShieldHealth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fGlobalMaxJetpackThrustSpeedMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fGlobalAirSpeedMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fGlobalAccelerationMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fGlobalSpeedCapMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSensorBlipFadeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nBlip, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nPhase0SeigeEnded, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_ResetGame, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGivePerfBonus, 0x8 )
			ADD_VAR( ::BoolProperty, bGivePrivateXP, 0x4 )
			ADD_VAR( ::BoolProperty, r_bCanPlaceDeployables, 0x1 )
			ADD_VAR( ::IntProperty, GeneratorDowntime, 0xFFFFFFFF )
			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyServerSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.ApplyServerSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CanPlaceDeployables( bool Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.CanPlaceDeployables" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPhase0SiegeEnded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.OnPhase0SiegeEnded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnResetGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.OnResetGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Timer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.Timer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool OnSameTeam( class Actor* A, class Actor* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.OnSameTeam" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = A;
				*( class Actor** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Blip(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.Blip" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangePhysicsType( int Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.ChangePhysicsType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsValidTeamPlayer( class TrPlayerReplicationInfo* TrPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.IsValidTeamPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerReplicationInfo** )( params + 0 ) = TrPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetWarmingUp( bool bWarmup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.SetWarmingUp" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWarmup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddPRI( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameReplicationInfo.AddPRI" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
