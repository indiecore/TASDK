#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Controller." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Controller." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Controller." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Controller : public Actor
	{
	public:
			ADD_OBJECT( Pawn, Pawn )
			ADD_OBJECT( PlayerReplicationInfo, PlayerReplicationInfo )
			ADD_VAR( ::BoolProperty, bGodMode, 0x2 )
			ADD_STRUCT( ::VectorProperty, NavMeshPath_SearchExtent_Modifier, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, OldBasedRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LaneOffset, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, Enemy )
			ADD_VAR( ::FloatProperty, MaxMoveTowardPawnTargetTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HighJumpNodeCostModifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InUseNodeCostMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SightCounterInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SightCounter, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FailedReachLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FailedReachTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, LastFailedReach )
			ADD_OBJECT( Pawn, ShotTarget )
			ADD_STRUCT( ::VectorProperty, ViewZ, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ViewY, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ViewX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroundPitchTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MoveFailureCount, 0xFFFFFFFF )
			ADD_OBJECT( Actor, FailedMoveTarget )
			ADD_OBJECT( InterpActor, PendingMover )
			ADD_VAR( ::FloatProperty, LastRouteFind, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RouteDist, 0xFFFFFFFF )
			ADD_OBJECT( Actor, RouteGoal )
			ADD_STRUCT( ::VectorProperty, CurrentPathDir, 0xFFFFFFFF )
			ADD_OBJECT( ReachSpec, NextRoutePath )
			ADD_OBJECT( ReachSpec, CurrentPath )
			ADD_OBJECT( NavigationPoint, StartSpot )
			ADD_OBJECT( Actor, GoalList )
			ADD_OBJECT( Actor, Focus )
			ADD_OBJECT( Actor, MoveTarget )
			ADD_VAR( ::FloatProperty, MoveTimer, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, OverrideSearchStart, 0xFFFFFFFF )
			ADD_OBJECT( NavigationHandle, NavigationHandle )
			ADD_OBJECT( ScriptClass, NavigationHandleClass )
			ADD_VAR( ::FloatProperty, MinHitWall, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bAltFire, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bFire, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUsingPathLanes, 0x20000 )
			ADD_VAR( ::BoolProperty, bSeeFriendly, 0x10000 )
			ADD_VAR( ::BoolProperty, bPreciseDestination, 0x8000 )
			ADD_VAR( ::BoolProperty, bNotifyFallingHitWall, 0x4000 )
			ADD_VAR( ::BoolProperty, bSkipExtraLOSChecks, 0x2000 )
			ADD_VAR( ::BoolProperty, bLOSflag, 0x1000 )
			ADD_VAR( ::BoolProperty, bForceStrafe, 0x800 )
			ADD_VAR( ::BoolProperty, bPreparingMove, 0x400 )
			ADD_VAR( ::BoolProperty, bAdjusting, 0x200 )
			ADD_VAR( ::BoolProperty, bCanDoSpecial, 0x100 )
			ADD_VAR( ::BoolProperty, bAdvancedTactics, 0x80 )
			ADD_VAR( ::BoolProperty, bOverrideSearchStart, 0x40 )
			ADD_VAR( ::BoolProperty, bNotifyApex, 0x20 )
			ADD_VAR( ::BoolProperty, bNotifyPostLanded, 0x10 )
			ADD_VAR( ::BoolProperty, bSlowerZAcquire, 0x8 )
			ADD_VAR( ::BoolProperty, bSoaking, 0x4 )
			ADD_VAR( ::BoolProperty, bIsPlayer, 0x1 )
			ADD_OBJECT( Controller, NextController )
			ADD_VAR( ::IntProperty, PlayerNum, 0xFFFFFFFF )
			bool IsLocalPlayerController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.IsLocalPlayerController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RouteCache_Empty(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.RouteCache_Empty" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RouteCache_AddItem( class NavigationPoint* Nav )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.RouteCache_AddItem" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavigationPoint** )params = Nav;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RouteCache_InsertItem( class NavigationPoint* Nav, int Idx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.RouteCache_InsertItem" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavigationPoint** )params = Nav;
				*( int* )( params + 4 ) = Idx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RouteCache_RemoveItem( class NavigationPoint* Nav )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.RouteCache_RemoveItem" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavigationPoint** )params = Nav;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RouteCache_RemoveIndex( int InIndex, int Count )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.RouteCache_RemoveIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = InIndex;
				*( int* )( params + 4 ) = Count;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFocalPoint( Vector FP, bool bOffsetFromBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SetFocalPoint" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = FP;
				*( bool* )( params + 12 ) = bOffsetFromBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetFocalPoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GetFocalPoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void SetDestinationPosition( Vector Dest, bool bOffsetFromBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SetDestinationPosition" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = Dest;
				*( bool* )( params + 12 ) = bOffsetFromBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetDestinationPosition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GetDestinationPosition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void SetAdjustLocation( Vector NewLoc, bool bAdjust, bool bOffsetFromBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SetAdjustLocation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = NewLoc;
				*( bool* )( params + 12 ) = bAdjust;
				*( bool* )( params + 16 ) = bOffsetFromBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetAdjustLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GetAdjustLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void NotifyPathChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyPathChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.BeginAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )params = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAnimPosition( ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SetAnimPosition" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )params = SlotName;
				*( int* )( params + 8 ) = ChannelIndex;
				*( ScriptName* )( params + 12 ) = InAnimSeqName;
				*( float* )( params + 20 ) = InPosition;
				*( bool* )( params + 24 ) = bFireNotifies;
				*( bool* )( params + 28 ) = bLooping;
				*( bool* )( params + 32 ) = bEnableRootMotion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.FinishAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )params = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PlayActorFaceFXAnim( class FaceFXAnimSet* AnimSet, ScriptArray< wchar_t > GroupName, ScriptArray< wchar_t > SeqName, class SoundCue* SoundCueToPlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.PlayActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class FaceFXAnimSet** )params = AnimSet;
				*( ScriptArray< wchar_t >* )( params + 4 ) = GroupName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = SeqName;
				*( class SoundCue** )( params + 28 ) = SoundCueToPlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StopActorFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.StopActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMorphWeight( ScriptName MorphNodeName, float MorphWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SetMorphWeight" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = MorphNodeName;
				*( float* )( params + 8 ) = MorphWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkelControlScale( ScriptName SkelControlName, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SetSkelControlScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SkelControlName;
				*( float* )( params + 8 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetLocation( Vector NewLocation, Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ClientSetLocation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = NewLocation;
				*( Rotator* )( params + 12 ) = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetRotation( Rotator NewRotation, bool bResetCamera )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ClientSetRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )params = NewRotation;
				*( bool* )( params + 12 ) = bResetCamera;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPossess( class SeqAct_Possess* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.OnPossess" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Possess** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Possess( class Pawn* inPawn, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.Possess" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = inPawn;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnPossess(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.UnPossess" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnDied( class Pawn* inPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.PawnDied" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = inPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GamePlayEndedState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GamePlayEndedState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyPostLanded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyPostLanded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CleanupPRI(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.CleanupPRI" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Restart( bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.Restart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool BeyondFogDistance( Vector ViewPoint, Vector OtherPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.BeyondFogDistance" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = ViewPoint;
				*( Vector* )( params + 12 ) = OtherPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EnemyJustTeleported(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.EnemyJustTeleported" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTakeHit( class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyTakeHit" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Controller** )params = InstigatedBy;
				*( Vector* )( params + 4 ) = HitLocation;
				*( int* )( params + 16 ) = Damage;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitPlayerReplicationInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.InitPlayerReplicationInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void ServerRestartPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ServerRestartPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerGivePawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ServerGivePawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCharacter( ScriptArray< wchar_t > inCharacter )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SetCharacter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = inCharacter;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameHasEnded( class Actor* EndGameFocus, bool bIsWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GameHasEnded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = EndGameFocus;
				*( bool* )( params + 4 ) = bIsWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyKilled( class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* damageTyp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyKilled" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = Killed;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = damageTyp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyProjLanded( class Projectile* Proj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyProjLanded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )params = Proj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WarnProjExplode( class Projectile* Proj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.WarnProjExplode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )params = Proj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float RatePickup( class Actor* PickupHolder, ScriptClass* inPickup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.RatePickup" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = PickupHolder;
				*( ScriptClass** )( params + 4 ) = inPickup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool FireWeaponAt( class Actor* inActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.FireWeaponAt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = inActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StopFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.StopFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RoundHasEnded( class Actor* EndRoundFocus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.RoundHasEnded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = EndRoundFocus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandlePickup( class Inventory* Inv )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.HandlePickup" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Inventory** )params = Inv;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Rotator GetAdjustedAimFor( class Weapon* W, Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GetAdjustedAimFor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )params = W;
				*( Vector* )( params + 4 ) = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void InstantWarnTarget( class Actor* InTarget, class Weapon* FiredWeapon, Vector FireDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.InstantWarnTarget" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = InTarget;
				*( class Weapon** )( params + 4 ) = FiredWeapon;
				*( Vector* )( params + 8 ) = FireDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveWarning( class Pawn* shooter, float projSpeed, Vector FireDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ReceiveWarning" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = shooter;
				*( float* )( params + 4 ) = projSpeed;
				*( Vector* )( params + 8 ) = FireDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveProjectileWarning( class Projectile* Proj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ReceiveProjectileWarning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )params = Proj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchToBestWeapon( bool bForceNewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SwitchToBestWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForceNewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSwitchToBestWeapon( bool bForceNewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ClientSwitchToBestWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForceNewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyChangedWeapon( class Weapon* PrevWeapon, class Weapon* NewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyChangedWeapon" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )params = PrevWeapon;
				*( class Weapon** )( params + 4 ) = NewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool LineOfSightTo( class Actor* Other, Vector chkLocation, bool bTryAlternateTargetLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.LineOfSightTo" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 4 ) = chkLocation;
				*( bool* )( params + 16 ) = bTryAlternateTargetLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanSee( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.CanSee" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanSeeByPoints( Vector ViewLocation, Vector TestLocation, Rotator ViewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.CanSeeByPoints" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )params = ViewLocation;
				*( Vector* )( params + 12 ) = TestLocation;
				*( Rotator* )( params + 24 ) = ViewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Pawn* PickTarget( ScriptClass* TargetClass, float &bestAim, float &bestDist, Vector FireDir, Vector projStart, float MaxRange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.PickTarget" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptClass** )params = TargetClass;
				*( float* )( params + 4 ) = bestAim;
				*( float* )( params + 8 ) = bestDist;
				*( Vector* )( params + 12 ) = FireDir;
				*( Vector* )( params + 24 ) = projStart;
				*( float* )( params + 36 ) = MaxRange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				bestAim = *( float* )( params + 4 );
				bestDist = *( float* )( params + 8 );
				return *( class Pawn** )( params + function->return_val_offset() );
			}

			void HearNoise( float Loudness, class Actor* NoiseMaker, ScriptName NoiseType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.HearNoise" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )params = Loudness;
				*( class Actor** )( params + 4 ) = NoiseMaker;
				*( ScriptName* )( params + 8 ) = NoiseType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeePlayer( class Pawn* Seen )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SeePlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Seen;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeeMonster( class Pawn* Seen )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SeeMonster" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Seen;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnemyNotVisible(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.EnemyNotVisible" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveTo( Vector NewDestination, class Actor* ViewFocus, float DestinationOffset, bool bShouldWalk )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.MoveTo" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = NewDestination;
				*( class Actor** )( params + 12 ) = ViewFocus;
				*( float* )( params + 16 ) = DestinationOffset;
				*( bool* )( params + 20 ) = bShouldWalk;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveToDirectNonPathPos( Vector NewDestination, class Actor* ViewFocus, float DestinationOffset, bool bShouldWalk )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.MoveToDirectNonPathPos" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = NewDestination;
				*( class Actor** )( params + 12 ) = ViewFocus;
				*( float* )( params + 16 ) = DestinationOffset;
				*( bool* )( params + 20 ) = bShouldWalk;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveToward( class Actor* NewTarget, class Actor* ViewFocus, float DestinationOffset, bool bUseStrafing, bool bShouldWalk )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.MoveToward" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = NewTarget;
				*( class Actor** )( params + 4 ) = ViewFocus;
				*( float* )( params + 8 ) = DestinationOffset;
				*( bool* )( params + 12 ) = bUseStrafing;
				*( bool* )( params + 16 ) = bShouldWalk;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupSpecialPathAbilities(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SetupSpecialPathAbilities" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.FinishRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* FindPathTo( Vector aPoint, int MaxPathLength, bool bReturnPartial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.FindPathTo" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = aPoint;
				*( int* )( params + 12 ) = MaxPathLength;
				*( bool* )( params + 16 ) = bReturnPartial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			class Actor* FindPathToward( class Actor* anActor, bool bWeightDetours, int MaxPathLength, bool bReturnPartial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.FindPathToward" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )params = anActor;
				*( bool* )( params + 4 ) = bWeightDetours;
				*( int* )( params + 8 ) = MaxPathLength;
				*( bool* )( params + 12 ) = bReturnPartial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			class Actor* FindPathTowardNearest( ScriptClass* GoalClass, bool bWeightDetours, int MaxPathLength, bool bReturnPartial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.FindPathTowardNearest" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = GoalClass;
				*( bool* )( params + 4 ) = bWeightDetours;
				*( int* )( params + 8 ) = MaxPathLength;
				*( bool* )( params + 12 ) = bReturnPartial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			class NavigationPoint* FindRandomDest(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.FindRandomDest" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			class Actor* FindPathToIntercept( class Pawn* P, class Actor* InRouteGoal, bool bWeightDetours, int MaxPathLength, bool bReturnPartial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.FindPathToIntercept" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = P;
				*( class Actor** )( params + 4 ) = InRouteGoal;
				*( bool* )( params + 8 ) = bWeightDetours;
				*( int* )( params + 12 ) = MaxPathLength;
				*( bool* )( params + 16 ) = bReturnPartial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool PointReachable( Vector aPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.PointReachable" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = aPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ActorReachable( class Actor* anActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ActorReachable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = anActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void MoveUnreachable( Vector AttemptedDest, class Actor* AttemptedTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.MoveUnreachable" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = AttemptedDest;
				*( class Actor** )( params + 12 ) = AttemptedTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PickWallAdjust( Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.PickWallAdjust" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void WaitForLanding( float waitDuration )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.WaitForLanding" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = waitDuration;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LongFall(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.LongFall" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndClimbLadder(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.EndClimbLadder" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MayFall( bool bFloor, Vector FloorNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.MayFall" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bFloor;
				*( Vector* )( params + 4 ) = FloorNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowDetourTo( class NavigationPoint* N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.AllowDetourTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavigationPoint** )params = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void WaitForMover( class InterpActor* M )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.WaitForMover" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpActor** )params = M;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool MoverFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.MoverFinished" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UnderLift( class LiftCenter* Lift )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.UnderLift" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LiftCenter** )params = Lift;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HandlePathObstruction( class Actor* BlockedBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.HandlePathObstruction" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = BlockedBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetPlayerViewPoint( Vector &out_Location, Rotator &out_Rotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GetPlayerViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = out_Location;
				*( Rotator* )( params + 12 ) = out_Rotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Location = *( Vector* )params;
				out_Rotation = *( Rotator* )( params + 12 );
			}

			void GetActorEyesViewPoint( Vector &out_Location, Rotator &out_Rotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GetActorEyesViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = out_Location;
				*( Rotator* )( params + 12 ) = out_Rotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Location = *( Vector* )params;
				out_Rotation = *( Rotator* )( params + 12 );
			}

			bool IsAimingAt( class Actor* ATarget, float Epsilon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.IsAimingAt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = ATarget;
				*( float* )( params + 4 ) = Epsilon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LandingShake(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.LandingShake" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyPhysicsVolumeChange( class PhysicsVolume* NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyPhysicsVolumeChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicsVolume** )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NotifyHeadVolumeChange( class PhysicsVolume* NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyHeadVolumeChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicsVolume** )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NotifyLanded( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyLanded" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NotifyHitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyHitWall" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyFallingHitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyFallingHitWall" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NotifyBump( class Actor* Other, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyBump" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 4 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyJumpApex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyJumpApex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyMissedJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyMissedJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReachedPreciseDestination(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ReachedPreciseDestination" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool InLatentExecution( int LatentActionNumber )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.InLatentExecution" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = LatentActionNumber;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StopLatentExecution(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.StopLatentExecution" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			ScriptArray< wchar_t > GetHumanReadableName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GetHumanReadableName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool IsDead(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.IsDead" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnTeleport( class SeqAct_Teleport* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.OnTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Teleport** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggleGodMode( class SeqAct_ToggleGodMode* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.OnToggleGodMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ToggleGodMode** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetPhysics( class SeqAct_SetPhysics* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.OnSetPhysics" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetPhysics** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetVelocity( class SeqAct_SetVelocity* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.OnSetVelocity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetVelocity** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyCoverDisabled( class CoverLink* Link, int SlotIdx, bool bAdjacentIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyCoverDisabled" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class CoverLink** )params = Link;
				*( int* )( params + 4 ) = SlotIdx;
				*( bool* )( params + 8 ) = bAdjacentIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyCoverAdjusted(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyCoverAdjusted" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NotifyCoverClaimViolation( class Controller* NewClaim, class CoverLink* Link, int SlotIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyCoverClaimViolation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )params = NewClaim;
				*( class CoverLink** )( params + 4 ) = Link;
				*( int* )( params + 8 ) = SlotIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnModifyHealth( class SeqAct_ModifyHealth* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.OnModifyHealth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ModifyHealth** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyAddInventory( class Inventory* NewItem )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.NotifyAddInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Inventory** )params = NewItem;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggleHidden( class SeqAct_ToggleHidden* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.OnToggleHidden" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ToggleHidden** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsSpectating(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.IsSpectating" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsInCombat( bool bForceCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.IsInCombat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForceCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CurrentLevelUnloaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.CurrentLevelUnloaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMessage( class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.SendMessage" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerReplicationInfo** )params = Recipient;
				*( ScriptName* )( params + 4 ) = MessageType;
				*( float* )( params + 12 ) = Wait;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReadyForLift(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.ReadyForLift" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitNavigationHandle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.InitNavigationHandle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationStarted( class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.InterpolationStarted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SeqAct_Interp** )params = InterpAction;
				*( class InterpGroupInst** )( params + 4 ) = GroupInst;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationFinished( class SeqAct_Interp* InterpAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.InterpolationFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Interp** )params = InterpAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GeneratePathToActor( class Actor* Goal, float WithinDistance, bool bAllowPartialPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GeneratePathToActor" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Actor** )params = Goal;
				*( float* )( params + 4 ) = WithinDistance;
				*( bool* )( params + 8 ) = bAllowPartialPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GeneratePathToLocation( Vector Goal, float WithinDistance, bool bAllowPartialPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Controller.GeneratePathToLocation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = Goal;
				*( float* )( params + 12 ) = WithinDistance;
				*( bool* )( params + 16 ) = bAllowPartialPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
