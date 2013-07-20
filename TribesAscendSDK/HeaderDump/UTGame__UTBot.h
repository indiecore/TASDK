#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTBot." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTBot." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTBot." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTBot : public UDKBot
	{
	public:
			ADD_OBJECT( Actor, NoVehicleGoal )
			ADD_STRUCT( ::VectorProperty, DirectionHint, 0xFFFFFFFF )
			Vector GetDirectionHint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.GetDirectionHint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( ScriptClass, KilledVehicleClass )
			float RatePickup( class Actor* PickupHolder, ScriptClass* InvClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.RatePickup" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = PickupHolder;
				*( ScriptClass** )( params + 4 ) = InvClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bHuntPlayer, 0x1 )
			ADD_OBJECT( ScriptClass, FavoriteWeapon )
			bool PriorityObjective(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.PriorityObjective" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float RateWeapon( class Weapon* W )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.RateWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )params = W;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool WeaponFireAgain( bool bFinishedFire )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.WeaponFireAgain" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bFinishedFire;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NeedWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTDefensePoint, DefensePoint )
			bool DoWaitForLanding(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DoWaitForLanding" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DelayedLeaveVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DelayedLeaveVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bJustLanded, 0x8000 )
			bool NotifyLanded( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyLanded" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetFall(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetFall" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::StrProperty, GoalString, 0xFFFFFFFF )
			bool CustomActionFunc( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CustomActionFunc" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )params = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, LastInjuredVoiceMessageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastCanAttackCheckTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, LastFireTarget )
			ADD_VAR( ::FloatProperty, LastTryHoverboardTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastActionMusicUpdate, 0xFFFFFFFF )
			ADD_OBJECT( Actor, ScriptedTarget )
			ADD_STRUCT( ::VectorProperty, LastKillerPosition, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastKnownPosition, 0xFFFFFFFF )
			ADD_OBJECT( Controller, OldOrderGiver )
			ADD_VAR( ::NameProperty, OldOrders, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, OrderNames, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GatherTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastFireAttempt, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumRandomJumps, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CampTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastSearchWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastSearchTime, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, FailedHuntEnemy )
			ADD_VAR( ::FloatProperty, FailedHuntTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastRespawnTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StopStartTime, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, DefensivePosition )
			ADD_VAR( ::FloatProperty, ReTaskTime, 0xFFFFFFFF )
			ADD_OBJECT( UTBot, NextSquadMember )
			ADD_VAR( ::StrProperty, SoakString, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldMessageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Jumpiness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ReactionTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Tactics, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CombatStyle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrafingAbility, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseAggressiveness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Accuracy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseAlertness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForcedFlagDropTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RetreatStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastUnderFire, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StartTacticalTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, StartleActor )
			ADD_VAR( ::FloatProperty, LoseEnemyCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Aggression, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AcquireTime, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, BlockedPath )
			ADD_VAR( ::FloatProperty, LastAttractCheck, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Aggressiveness, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, HidingSpot, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastTauntIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OldMessageID, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, OldMessageType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpecialJumpZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ImpactJumpZ, 0xFFFFFFFF )
			ADD_OBJECT( Actor, ImpactTarget )
			ADD_VAR( ::BoolProperty, bResetCombatTimer, 0x40000000 )
			ADD_VAR( ::BoolProperty, bCheckDriverPickups, 0x20000000 )
			ADD_VAR( ::BoolProperty, bDirectHunt, 0x10000000 )
			ADD_VAR( ::BoolProperty, bFinalStretch, 0x8000000 )
			ADD_VAR( ::BoolProperty, bSpawnedByKismet, 0x4000000 )
			ADD_VAR( ::BoolProperty, bBetrayTeam, 0x2000000 )
			ADD_VAR( ::BoolProperty, bShortCamp, 0x1000000 )
			ADD_VAR( ::BoolProperty, bForceNoDetours, 0x800000 )
			ADD_VAR( ::BoolProperty, bSendFlagMessage, 0x400000 )
			ADD_VAR( ::BoolProperty, bScriptedFrozen, 0x200000 )
			ADD_VAR( ::BoolProperty, bAllowedToImpactJump, 0x100000 )
			ADD_VAR( ::BoolProperty, bPendingDoubleJump, 0x80000 )
			ADD_VAR( ::BoolProperty, bHasSuperWeapon, 0x40000 )
			ADD_VAR( ::BoolProperty, bIgnoreEnemyChange, 0x20000 )
			ADD_VAR( ::BoolProperty, bRecommendFastMove, 0x10000 )
			ADD_VAR( ::BoolProperty, bPursuingFlag, 0x4000 )
			ADD_VAR( ::BoolProperty, bMustCharge, 0x2000 )
			ADD_VAR( ::BoolProperty, bStoppedFiring, 0x1000 )
			ADD_VAR( ::BoolProperty, bFireSuccess, 0x800 )
			ADD_VAR( ::BoolProperty, bForcedDirection, 0x400 )
			ADD_VAR( ::BoolProperty, bHasFired, 0x200 )
			ADD_VAR( ::BoolProperty, bWasNearObjective, 0x100 )
			ADD_VAR( ::BoolProperty, bTacticalDoubleJump, 0x80 )
			ADD_VAR( ::BoolProperty, bReachedGatherPoint, 0x40 )
			ADD_VAR( ::BoolProperty, bInitLifeMessage, 0x20 )
			ADD_VAR( ::BoolProperty, bFrustrated, 0x10 )
			ADD_VAR( ::BoolProperty, bChangeDir, 0x8 )
			ADD_VAR( ::BoolProperty, bStrafeDir, 0x4 )
			ADD_VAR( ::BoolProperty, bCanFire, 0x2 )
			ADD_VAR( ::FloatProperty, LastWarningTime, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, InstantWarningShooter )
			void EnemyJustTeleported(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.EnemyJustTeleported" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WasKilledBy( class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.WasKilledBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartMonitoring( class Pawn* P, float MaxDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.StartMonitoring" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = P;
				*( float* )( params + 4 ) = MaxDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnDied( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.PawnDied" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnedByKismet(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SpawnedByKismet" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool LandingShake(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.LandingShake" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasTimedPowerup(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.HasTimedPowerup" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyAddInventory( class Inventory* NewItem )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyAddInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Inventory** )params = NewItem;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupSpecialPathAbilities(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetupSpecialPathAbilities" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NotifyHitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyHitWall" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FearThisSpot( class UTAvoidMarker* aSpot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FearThisSpot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTAvoidMarker** )params = aSpot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Startle( class Actor* Feared )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.Startle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Feared;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCombatTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetCombatTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanImpactJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CanImpactJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TimeDJReset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.TimeDJReset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetDoubleJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ResetDoubleJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WaitForMover( class InterpActor* M )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.WaitForMover" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpActor** )params = M;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReadyForLift(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ReadyForLift" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldFireAgain(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ShouldFireAgain" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TimedFireWeaponAtEnemy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.TimedFireWeaponAtEnemy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FireWeaponAt( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FireWeaponAt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanAttack( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CanAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnAIStartFireAt( class UTSeqAct_AIStartFireAt* FireAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.OnAIStartFireAt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_AIStartFireAt** )params = FireAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TimedFireWeaponAtScriptedTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.TimedFireWeaponAtScriptedTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.StopFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAIStopFire( class UTSeqAct_AIStopFire* FireAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.OnAIStopFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_AIStopFire** )params = FireAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float WeaponPreference( class Weapon* W )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.WeaponPreference" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )params = W;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool ProficientWithWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ProficientWithWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanComboMoving(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CanComboMoving" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanCombo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CanCombo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DisplayDebug( class HUD* HUD, float &YL, float &YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = YL;
				*( float* )( params + 8 ) = YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				YL = *( float* )( params + 4 );
				YPos = *( float* )( params + 8 );
			}

			ScriptName GetOrders(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.GetOrders" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void YellAt( class PlayerReplicationInfo* Moron )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.YellAt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = Moron;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMessage( class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SendMessage" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerReplicationInfo** )params = Recipient;
				*( ScriptName* )( params + 4 ) = MessageType;
				*( float* )( params + 12 ) = Wait;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBotOrders( ScriptName NewOrders, class Controller* OrderGiver, bool bShouldAck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetBotOrders" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = NewOrders;
				*( class Controller** )( params + 8 ) = OrderGiver;
				*( bool* )( params + 12 ) = bShouldAck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTemporaryOrders( ScriptName NewOrders, class Controller* OrderGiver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetTemporaryOrders" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = NewOrders;
				*( class Controller** )( params + 8 ) = OrderGiver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearTemporaryOrders(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ClearTemporaryOrders" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HearNoise( float Loudness, class Actor* NoiseMaker, ScriptName NoiseType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.HearNoise" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )params = Loudness;
				*( class Actor** )( params + 4 ) = NoiseMaker;
				*( ScriptName* )( params + 8 ) = NoiseType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeePlayer( class Pawn* SeenPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SeePlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = SeenPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAttractionState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetAttractionState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ClearShot( Vector TargetLoc, bool bImmediateFire )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ClearShot" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = TargetLoc;
				*( bool* )( params + 12 ) = bImmediateFire;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanStakeOut(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CanStakeOut" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CheckIfShouldCrouch( Vector StartPosition, Vector TargetPosition, float probability )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CheckIfShouldCrouch" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = StartPosition;
				*( Vector* )( params + 12 ) = TargetPosition;
				*( float* )( params + 24 ) = probability;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsSniping(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.IsSniping" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FreePoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FreePoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AssignSquadResponsibility(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.AssignSquadResponsibility" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float RelativeStrength( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.RelativeStrength" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetEnemyInfo( bool bNewEnemyVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetEnemyInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewEnemyVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnemyChanged( bool bNewEnemyVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.EnemyChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewEnemyVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool StrafeFromDamage( float Damage, ScriptClass* DamageType, bool bFindDest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.StrafeFromDamage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = Damage;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( bool* )( params + 8 ) = bFindDest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyPhysicsVolumeChange( class PhysicsVolume* NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyPhysicsVolumeChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicsVolume** )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MayDodgeToMoveTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.MayDodgeToMoveTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyJumpApex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyJumpApex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyMissedJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyMissedJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Possess( class Pawn* aPawn, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.Possess" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = aPawn;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Initialize( float InSkill, void* &BotInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.Initialize" );
				byte *params = ( byte* )( malloc( 116 ) );
				*( float* )params = InSkill;
				*( void** )( params + 4 ) = BotInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BotInfo = *( void** )( params + 4 );
			}

			void ResetSkill(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ResetSkill" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMaxDesiredSpeed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetMaxDesiredSpeed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPeripheralVision(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetPeripheralVision" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAlertness( float NewAlertness )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetAlertness" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewAlertness;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WhatToDoNext(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.WhatToDoNext" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ExecuteWhatToDoNext(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ExecuteWhatToDoNext" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnterVehicle( class Vehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.EnterVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )params = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LeaveVehicle( bool bBlocking )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.LeaveVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bBlocking;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleFightEnemy( bool bCanCharge, float EnemyStrength )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.VehicleFightEnemy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bCanCharge;
				*( float* )( params + 4 ) = EnemyStrength;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FightEnemy( bool bCanCharge, float EnemyStrength )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FightEnemy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bCanCharge;
				*( float* )( params + 4 ) = EnemyStrength;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoRangedAttackOn( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DoRangedAttackOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChooseAttackMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ChooseAttackMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FindSuperPickup( float MaxDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FindSuperPickup" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = MaxDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindInventoryGoal( float BestWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FindInventoryGoal" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = BestWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TossFlagToPlayer( class Controller* OrderGiver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.TossFlagToPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = OrderGiver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PickRetreatDestination(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.PickRetreatDestination" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SoakStop( ScriptArray< wchar_t > problem )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SoakStop" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = problem;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FindRoamDest(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FindRoamDest" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Restart( bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.Restart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckPathToGoalAround( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CheckPathToGoalAround" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearPathFor( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ClearPathFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AdjustAround( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.AdjustAround" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NotifyBump( class Actor* Other, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyBump" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 4 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyPostLanded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyPostLanded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TimedDodgeToMoveTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.TimedDodgeToMoveTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool StartMoveToward( class Actor* O )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.StartMoveToward" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = O;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetRouteToGoal( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SetRouteToGoal" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowDetourTo( class NavigationPoint* N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.AllowDetourTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavigationPoint** )params = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindBestPathToward( class Actor* A, bool bCheckedReach, bool bAllowDetour )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FindBestPathToward" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Actor** )params = A;
				*( bool* )( params + 4 ) = bCheckedReach;
				*( bool* )( params + 8 ) = bAllowDetour;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckFutureSight( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.CheckFutureSight" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float AdjustAimError( float TargetDist, bool bInstantProj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.AdjustAimError" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = TargetDist;
				*( bool* )( params + 4 ) = bInstantProj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Rotator GetAdjustedAimFor( class Weapon* InWeapon, Vector projStart )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.GetAdjustedAimFor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )params = InWeapon;
				*( Vector* )( params + 4 ) = projStart;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool TryDuckTowardsMoveTarget( Vector Dir, Vector Y )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.TryDuckTowardsMoveTarget" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = Dir;
				*( Vector* )( params + 12 ) = Y;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DelayedWarning(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DelayedWarning" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveProjectileWarning( class Projectile* Proj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ReceiveProjectileWarning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )params = Proj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTakeHit( class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyTakeHit" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Controller** )params = InstigatedBy;
				*( Vector* )( params + 4 ) = HitLocation;
				*( int* )( params + 16 ) = Damage;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DelayedInstantWarning(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DelayedInstantWarning" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveWarning( class Pawn* shooter, float projSpeed, Vector FireDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ReceiveWarning" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = shooter;
				*( float* )( params + 4 ) = projSpeed;
				*( Vector* )( params + 8 ) = FireDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveRunOverWarning( class UDKVehicle* V, float projSpeed, Vector VehicleDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ReceiveRunOverWarning" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class UDKVehicle** )params = V;
				*( float* )( params + 4 ) = projSpeed;
				*( Vector* )( params + 8 ) = VehicleDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyFallingHitWall( Vector HitNormal, class Actor* HitActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyFallingHitWall" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = HitActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MissedDodge(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.MissedDodge" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TryWallDodge( Vector HitNormal, class Actor* HitActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.TryWallDodge" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = HitActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ChangeStrafe(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ChangeStrafe" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TryToDuck( Vector duckDir, bool bReversed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.TryToDuck" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = duckDir;
				*( bool* )( params + 12 ) = bReversed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyKilled( class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.NotifyKilled" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = Killed;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* FaceMoveTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FaceMoveTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool ShouldStrafeTo( class Actor* WayPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ShouldStrafeTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = WayPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Actor* FaceActor( float StrafingModifier )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FaceActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = StrafingModifier;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			float SuperDesireability( class PickupFactory* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SuperDesireability" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PickupFactory** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool SuperPickupNotSpokenFor( class UTPickupFactory* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.SuperPickupNotSpokenFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPickupFactory** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DamageAttitudeTo( class Controller* Other, float Damage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DamageAttitudeTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = Other;
				*( float* )( params + 4 ) = Damage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsRetreating(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.IsRetreating" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnAIFreeze( class UTSeqAct_AIFreeze* FreezeAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.OnAIFreeze" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_AIFreeze** )params = FreezeAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsDefending(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.IsDefending" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldDefendPosition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ShouldDefendPosition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void MoveToDefensePoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.MoveToDefensePoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveAwayFrom( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.MoveAwayFrom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WanderOrCamp(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.WanderOrCamp" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableBumps(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.EnableBumps" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Celebrate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.Celebrate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceGiveWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.ForceGiveWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetDesiredOffset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.GetDesiredOffset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool LostContact( float MaxTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.LostContact" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = MaxTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LoseEnemy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.LoseEnemy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DoStakeOut(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DoStakeOut" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoCharge(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DoCharge" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoTacticalMove(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DoTacticalMove" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoRetreat(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DoRetreat" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DefendMelee( float Dist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.DefendMelee" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Dist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsStrafing(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.IsStrafing" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool EngageDirection( Vector StrafeDir, bool bForced )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.EngageDirection" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = StrafeDir;
				*( bool* )( params + 12 ) = bForced;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsHunting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.IsHunting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindViewSpot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FindViewSpot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Stopped(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.Stopped" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsShootingObjective(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.IsShootingObjective" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FocusOnLeader( bool bLeaderFiring )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.FocusOnLeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bLeaderFiring;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StopMovement(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.StopMovement" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PerformCustomAction(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.PerformCustomAction" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnderLift( class LiftCenter* M )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.UnderLift" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LiftCenter** )params = M;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HandlePathObstruction( class Actor* BlockedBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTBot.HandlePathObstruction" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = BlockedBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
