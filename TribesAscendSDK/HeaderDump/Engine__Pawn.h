#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Pawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Pawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Pawn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Pawn : public Actor
	{
	public:
			ADD_OBJECT( Controller, Controller )
			bool IsHumanControlled( class Controller* PawnController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsHumanControlled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = PawnController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsLocallyControlled( class Controller* PawnController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsLocallyControlled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = PawnController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PlayActorFaceFXAnim( class FaceFXAnimSet* AnimSet, ScriptArray< wchar_t > GroupName, ScriptArray< wchar_t > SeqName, class SoundCue* SoundCueToPlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class FaceFXAnimSet** )( params + 0 ) = AnimSet;
				*( ScriptArray< wchar_t >* )( params + 4 ) = GroupName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = SeqName;
				*( class SoundCue** )( params + 28 ) = SoundCueToPlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, MaxPitchLimit, 0xFFFFFFFF )
			ADD_OBJECT( Weapon, Weapon )
			ADD_OBJECT( InventoryManager, InvManager )
			bool StopFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.StopFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Rotator GetBaseAimRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetBaseAimRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bIsWalking, 0x4 )
			ScriptArray< wchar_t > GetHumanReadableName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetHumanReadableName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, EyeHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseEyeHeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Health, 0xFFFFFFFF )
			bool Died( class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Died" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetDefaultCameraMode( class PlayerController* RequestedBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetDefaultCameraMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = RequestedBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bForceRMVelocity, 0x100000 )
			ADD_STRUCT( ::VectorProperty, Floor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRootMotionFromInterpCurve, 0x8000000 )
			ADD_VAR( ::FloatProperty, CrouchHeight, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsCrouched, 0x10 )
			ADD_VAR( ::FloatProperty, MaxStepHeight, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceMaxAccel, 0x20000 )
			bool CanThrowWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CanThrowWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, VehicleCheckRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastStartTime, 0xFFFFFFFF )
			ADD_OBJECT( PhysicsVolume, HeadVolume )
			ADD_VAR( ::FloatProperty, BreathTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UnderWaterTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, WaterMovementState, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, LandMovementState, 0xFFFFFFFF )
			bool SetDesiredRotation( Rotator TargetDesiredRotation, bool InLockDesiredRotation, bool InUnlockWhenReached, float InterpolationTime, bool bResetRotationRate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetDesiredRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Rotator* )( params + 0 ) = TargetDesiredRotation;
				*( bool* )( params + 12 ) = InLockDesiredRotation;
				*( bool* )( params + 16 ) = InUnlockWhenReached;
				*( float* )( params + 20 ) = InterpolationTime;
				*( bool* )( params + 24 ) = bResetRotationRate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool DoJump( bool bUpdating )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.DoJump" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bUpdating;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetRemoteViewPitch( int NewRemoteViewPitch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetRemoteViewPitch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = NewRemoteViewPitch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, AccelRate, 0xFFFFFFFF )
			bool CannotJumpNow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CannotJumpNow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, WalkingPhysics, 0xFFFFFFFF )
			ADD_OBJECT( LadderVolume, OnLadder )
			ADD_VAR( ::BoolProperty, bUpAndOut, 0x2 )
			bool CheckWaterJump( Vector &WallNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CheckWaterJump" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = WallNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				WallNormal = *( Vector* )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, OutofWaterZ, 0xFFFFFFFF )
			bool TouchingWaterVolume(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TouchingWaterVolume" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReachedDestination( class Actor* Goal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ReachedDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Goal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SpecialMoveTo( class NavigationPoint* Start, class NavigationPoint* End, class Actor* Next )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SpecialMoveTo" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class NavigationPoint** )( params + 0 ) = Start;
				*( class NavigationPoint** )( params + 4 ) = End;
				*( class Actor** )( params + 8 ) = Next;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( NavigationPoint, Anchor )
			ADD_STRUCT( ::VectorProperty, RootMotionInterpCurveLastValue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RootMotionInterpCurrentTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RootMotionInterpRate, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, MIC_PawnHair )
			ADD_OBJECT( MaterialInstanceConstant, MIC_PawnMat )
			ADD_VAR( ::IntProperty, FailedLandingCount, 0xFFFFFFFF )
			ADD_OBJECT( RB_BodyInstance, PhysicsPushBody )
			ADD_VAR( ::IntProperty, ShotCount, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastFiringFlashLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FlashLocation, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, InventoryManagerClass )
			ADD_STRUCT( ::RotatorProperty, DesiredRotation, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AllowedYawError, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewPitchMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewPitchMin, 0xFFFFFFFF )
			ADD_OBJECT( Controller, LastHitBy )
			ADD_VAR( ::FloatProperty, AlwaysRelevantDistanceSquared, 0xFFFFFFFF )
			ADD_OBJECT( Vehicle, DrivenVehicle )
			ADD_VAR( ::FloatProperty, RBPushStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RBPushRadius, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TearOffMomentum, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, HitDamageType )
			ADD_STRUCT( ::VectorProperty, TakeHitLocation, 0xFFFFFFFF )
			ADD_OBJECT( PlayerStart, LastStartSpot )
			ADD_OBJECT( PlayerReplicationInfo, PlayerReplicationInfo )
			ADD_OBJECT( ScriptClass, ControllerClass )
			ADD_VAR( ::StrProperty, MenuName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageScaling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SoundDampening, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, noise2loudness, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, noise2other )
			ADD_VAR( ::FloatProperty, noise2time, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, noise2spot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, noise1loudness, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, noise1other )
			ADD_VAR( ::FloatProperty, noise1time, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, noise1spot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RMVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, KismetDeathDelayTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPainTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HealthMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SplashTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AIMaxFallSpeedFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxFallSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CrouchedPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MovementSpeedModifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WalkingPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AirControl, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxOutOfWaterStepHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, JumpZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LadderSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AirSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WaterSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroundSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SerpentineTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SerpentineDist, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SerpentineDir, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NextPathRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DestinationOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastValidAnchorTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FindAnchorFailedTime, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, LastAnchor )
			ADD_VAR( ::IntProperty, AnchorItem, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MeleeRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Buoyancy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Mass, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AvgPhysicsTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PeripheralVision, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SightRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Alertness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HearingThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDesiredSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DesiredSpeed, 0xFFFFFFFF )
			ADD_OBJECT( PathGoalEvaluator, PathGoalList )
			ADD_OBJECT( PathConstraint, PathConstraintList )
			ADD_VAR( ::FloatProperty, NonPreferredVehiclePathMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FullHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CrouchRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UncrouchTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FiringMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FlashCount, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RemoteViewPitch, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PathSearchType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDebugShowCameraLocation, 0x10000000 )
			ADD_VAR( ::BoolProperty, bNeedsBaseTickedFirst, 0x4000000 )
			ADD_VAR( ::BoolProperty, bUnlockWhenReached, 0x2000000 )
			ADD_VAR( ::BoolProperty, bLockDesiredRotation, 0x1000000 )
			ADD_VAR( ::BoolProperty, bDesiredRotationSet, 0x800000 )
			ADD_VAR( ::BoolProperty, bPlayedDeath, 0x400000 )
			ADD_VAR( ::BoolProperty, bForceRegularVelocity, 0x200000 )
			ADD_VAR( ::BoolProperty, bReplicateHealthToAll, 0x80000 )
			ADD_VAR( ::BoolProperty, bLimitFallAccel, 0x40000 )
			ADD_VAR( ::BoolProperty, bRunPhysicsWithNoController, 0x10000 )
			ADD_VAR( ::BoolProperty, bPathfindsAsVehicle, 0x8000 )
			ADD_VAR( ::BoolProperty, bModifyNavPointDest, 0x4000 )
			ADD_VAR( ::BoolProperty, bModifyReachSpecCost, 0x2000 )
			ADD_VAR( ::BoolProperty, bNoWeaponFiring, 0x1000 )
			ADD_VAR( ::BoolProperty, bCachedRelevant, 0x800 )
			ADD_VAR( ::BoolProperty, bStationary, 0x400 )
			ADD_VAR( ::BoolProperty, bRollToDesired, 0x200 )
			ADD_VAR( ::BoolProperty, bDontPossess, 0x100 )
			ADD_VAR( ::BoolProperty, bMuffledHearing, 0x80 )
			ADD_VAR( ::BoolProperty, bLOSHearing, 0x40 )
			ADD_VAR( ::BoolProperty, bAmbientCreature, 0x20 )
			ADD_VAR( ::BoolProperty, bCanPickupInventory, 0x10 )
			ADD_VAR( ::BoolProperty, bDisplayPathErrors, 0x8 )
			ADD_VAR( ::BoolProperty, bCanCoverSlip, 0x4 )
			ADD_VAR( ::BoolProperty, bCanLeap, 0x2 )
			ADD_VAR( ::BoolProperty, bCanSwatTurn, 0x1 )
			ADD_VAR( ::BoolProperty, bCanClimbCeilings, 0x80000000 )
			ADD_VAR( ::BoolProperty, bCanClimbUp, 0x40000000 )
			ADD_VAR( ::BoolProperty, bCanMantle, 0x20000000 )
			ADD_VAR( ::BoolProperty, bForceKeepAnchor, 0x10000000 )
			ADD_VAR( ::BoolProperty, bForceFloorCheck, 0x8000000 )
			ADD_VAR( ::BoolProperty, bPushesRigidBodies, 0x4000000 )
			ADD_VAR( ::BoolProperty, bDirectHitWall, 0x2000000 )
			ADD_VAR( ::BoolProperty, bSimGravityDisabled, 0x1000000 )
			ADD_VAR( ::BoolProperty, bCanBeBaseForPawns, 0x800000 )
			ADD_VAR( ::BoolProperty, bCanWalkOffLedges, 0x400000 )
			ADD_VAR( ::BoolProperty, bIgnoreForces, 0x200000 )
			ADD_VAR( ::BoolProperty, bSimulateGravity, 0x100000 )
			ADD_VAR( ::BoolProperty, bPartiallyOverLedge, 0x80000 )
			ADD_VAR( ::BoolProperty, bAllowLedgeOverhang, 0x40000 )
			ADD_VAR( ::BoolProperty, bStopAtLedges, 0x20000 )
			ADD_VAR( ::BoolProperty, bAvoidLedges, 0x10000 )
			ADD_VAR( ::BoolProperty, bCanStrafe, 0x8000 )
			ADD_VAR( ::BoolProperty, bCanClimbLadders, 0x4000 )
			ADD_VAR( ::BoolProperty, bCanFly, 0x2000 )
			ADD_VAR( ::BoolProperty, bCanSwim, 0x1000 )
			ADD_VAR( ::BoolProperty, bCanWalk, 0x800 )
			ADD_VAR( ::BoolProperty, bCanJump, 0x400 )
			ADD_VAR( ::BoolProperty, bJumpCapable, 0x200 )
			ADD_VAR( ::BoolProperty, bReducedSpeed, 0x100 )
			ADD_VAR( ::BoolProperty, bCrawler, 0x80 )
			ADD_VAR( ::BoolProperty, bCanCrouch, 0x40 )
			ADD_VAR( ::BoolProperty, bTryToUncrouch, 0x20 )
			ADD_VAR( ::BoolProperty, bWantsToCrouch, 0x8 )
			ADD_VAR( ::BoolProperty, bScriptTickSpecial, 0x1 )
			ADD_OBJECT( Actor, LastViewer )
			ADD_OBJECT( PlayerController, LastRealViewer )
			ADD_VAR( ::FloatProperty, NetRelevancyTime, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, NextPawn )
			ADD_STRUCT( ::VectorProperty, PartialLedgeMoveDir, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LedgeCheckThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WalkableFloorZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxJumpHeight, 0xFFFFFFFF )
			void SetScalarParameterInterp( void* &ScalarParameterInterp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetScalarParameterInterp" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = ScalarParameterInterp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ScalarParameterInterp = *( void** )( params + 0 );
			}

			bool CheatFly(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CheatFly" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheatWalk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CheatWalk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheatGhost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CheatGhost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsPlayerPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsPlayerPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Inventory* FindInventoryType( ScriptClass* DesiredClass, bool bAllowSubclass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FindInventoryType" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = DesiredClass;
				*( bool* )( params + 4 ) = bAllowSubclass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Inventory** )( params + function->return_val_offset() );
			}

			class Inventory* CreateInventory( ScriptClass* NewInvClass, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CreateInventory" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = NewInvClass;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Inventory** )( params + function->return_val_offset() );
			}

			bool InGodMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.InGodMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ValidAnchor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ValidAnchor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class NavigationPoint* GetBestAnchor( class Actor* TestActor, Vector TestLocation, bool bStartPoint, bool bOnlyCheckVisible, float &out_Dist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetBestAnchor" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )( params + 0 ) = TestActor;
				*( Vector* )( params + 4 ) = TestLocation;
				*( bool* )( params + 16 ) = bStartPoint;
				*( bool* )( params + 20 ) = bOnlyCheckVisible;
				*( float* )( params + 24 ) = out_Dist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Dist = *( float* )( params + 24 );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			class PathGoalEvaluator* CreatePathGoalEvaluator( ScriptClass* GoalEvalClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CreatePathGoalEvaluator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = GoalEvalClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PathGoalEvaluator** )( params + function->return_val_offset() );
			}

			float GetCollisionHeight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetCollisionHeight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Vector GetCollisionExtent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetCollisionExtent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Rotator GetViewRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetViewRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool CanGrabLadder(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CanGrabLadder" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool LineOfSightTo( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.LineOfSightTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PickWallAdjust( Vector WallHitNormal, class Actor* HitActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PickWallAdjust" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = WallHitNormal;
				*( class Actor** )( params + 12 ) = HitActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void LockDesiredRotation( bool Lock, bool InUnlockWhenReached )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.LockDesiredRotation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = Lock;
				*( bool* )( params + 4 ) = InUnlockWhenReached;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetDesiredRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ResetDesiredRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckDesiredRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CheckDesiredRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsDesiredRotationInUse(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsDesiredRotationInUse" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsDesiredRotationLocked(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsDesiredRotationLocked" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CacheAnimNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CacheAnimNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearAnimNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClearAnimNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateAnimSetList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.UpdateAnimSetList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BuildScriptAnimSetList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.BuildScriptAnimSetList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddAnimSets(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.AddAnimSets" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AnimSetListUpdated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.AnimSetListUpdated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RestoreAnimSetsToDefault(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.RestoreAnimSetsToDefault" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BeginAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.BeginAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_BeginAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MAT_BeginAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FinishAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_FinishAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MAT_FinishAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAnimPosition( ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetAnimPosition" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )( params + 0 ) = SlotName;
				*( int* )( params + 8 ) = ChannelIndex;
				*( ScriptName* )( params + 12 ) = InAnimSeqName;
				*( float* )( params + 20 ) = InPosition;
				*( bool* )( params + 24 ) = bFireNotifies;
				*( bool* )( params + 28 ) = bLooping;
				*( bool* )( params + 32 ) = bEnableRootMotion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_SetAnimPosition( ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MAT_SetAnimPosition" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )( params + 0 ) = SlotName;
				*( int* )( params + 8 ) = ChannelIndex;
				*( ScriptName* )( params + 12 ) = InAnimSeqName;
				*( float* )( params + 20 ) = InPosition;
				*( bool* )( params + 24 ) = bFireNotifies;
				*( bool* )( params + 28 ) = bLooping;
				*( bool* )( params + 32 ) = bEnableRootMotion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_SetAnimWeights(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MAT_SetAnimWeights" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_SetMorphWeight( ScriptName MorphNodeName, float MorphWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MAT_SetMorphWeight" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = MorphNodeName;
				*( float* )( params + 8 ) = MorphWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_SetSkelControlScale( ScriptName SkelControlName, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MAT_SetSkelControlScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SkelControlName;
				*( float* )( params + 8 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationStarted( class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.InterpolationStarted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SeqAct_Interp** )( params + 0 ) = InterpAction;
				*( class InterpGroupInst** )( params + 4 ) = GroupInst;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InterpolationFinished( class SeqAct_Interp* InterpAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.InterpolationFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Interp** )( params + 0 ) = InterpAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_BeginAIGroup( Vector StartLoc, Rotator StartRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MAT_BeginAIGroup" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = StartLoc;
				*( Rotator* )( params + 12 ) = StartRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_FinishAIGroup(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MAT_FinishAIGroup" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopActorFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.StopActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetFaceFXAudioComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetFaceFXAudioComponent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool IsActorPlayingFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsActorPlayingFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanActorPlayFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CanActorPlayFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnPlayFaceFXAnim( class SeqAct_PlayFaceFXAnim* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.OnPlayFaceFXAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_PlayFaceFXAnim** )( params + 0 ) = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FaceFXAudioFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FaceFXAudioFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class FaceFXAsset* GetActorFaceFXAsset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetActorFaceFXAsset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class FaceFXAsset** )( params + function->return_val_offset() );
			}

			void SetMorphWeight( ScriptName MorphNodeName, float MorphWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetMorphWeight" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = MorphNodeName;
				*( float* )( params + 8 ) = MorphWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkelControlScale( ScriptName SkelControlName, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetSkelControlScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SkelControlName;
				*( float* )( params + 8 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsAliveAndWell(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsAliveAndWell" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector AdjustDestination( class Actor* GoalActor, Vector Dest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.AdjustDestination" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )( params + 0 ) = GoalActor;
				*( Vector* )( params + 4 ) = Dest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool SuggestJumpVelocity( Vector &JumpVelocity, Vector Destination, Vector Start, bool bRequireFallLanding )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SuggestJumpVelocity" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( Vector* )( params + 0 ) = JumpVelocity;
				*( Vector* )( params + 12 ) = Destination;
				*( Vector* )( params + 24 ) = Start;
				*( bool* )( params + 36 ) = bRequireFallLanding;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				JumpVelocity = *( Vector* )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetFallDuration(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetFallDuration" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool IsValidEnemyTargetFor( class PlayerReplicationInfo* PRI, bool bNoPRIisEnemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsValidEnemyTargetFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = PRI;
				*( bool* )( params + 4 ) = bNoPRIisEnemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsInvisible(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsInvisible" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetAnchor( class NavigationPoint* NewAnchor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetAnchor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavigationPoint** )( params + 0 ) = NewAnchor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReachedPoint( Vector Point, class Actor* NewAnchor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ReachedPoint" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = Point;
				*( class Actor** )( params + 12 ) = NewAnchor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ForceCrouch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ForceCrouch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPushesRigidBodies( bool NewPush )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetPushesRigidBodies" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = NewPush;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReachedDesiredRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ReachedDesiredRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetBoundingCylinder( float &CollisionRadius, float &CollisionHeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetBoundingCylinder" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = CollisionRadius;
				*( float* )( params + 4 ) = CollisionHeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CollisionRadius = *( float* )( params + 0 );
				CollisionHeight = *( float* )( params + 4 );
			}

			bool InitRagdoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.InitRagdoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TermRagdoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TermRagdoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SpecialMoveThruEdge( byte Type, int Dir, Vector MoveStart, Vector MoveDest, class Actor* RelActor, int RelItem )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SpecialMoveThruEdge" );
				byte *params = ( byte* )( malloc( 37 ) );
				*( byte* )( params + 0 ) = Type;
				*( int* )( params + 4 ) = Dir;
				*( Vector* )( params + 8 ) = MoveStart;
				*( Vector* )( params + 20 ) = MoveDest;
				*( class Actor** )( params + 32 ) = RelActor;
				*( int* )( params + 36 ) = RelItem;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetBaseEyeheight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetBaseEyeheight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayerChangedTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayerChangedTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.StopFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetWeaponFiringMode( class Weapon* InWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetWeaponFiringMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void SetFiringMode( class Weapon* InWeapon, byte InFiringMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetFiringMode" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( byte* )( params + 4 ) = InFiringMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FiringModeUpdated( class Weapon* InWeapon, byte InFiringMode, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FiringModeUpdated" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( byte* )( params + 4 ) = InFiringMode;
				*( bool* )( params + 8 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementFlashCount( class Weapon* InWeapon, byte InFiringMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IncrementFlashCount" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( byte* )( params + 4 ) = InFiringMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlashCountUpdated( class Weapon* InWeapon, byte InFlashCount, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FlashCountUpdated" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( byte* )( params + 4 ) = InFlashCount;
				*( bool* )( params + 8 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlashCount( class Weapon* InWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClearFlashCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFlashLocation( class Weapon* InWeapon, byte InFiringMode, Vector NewLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetFlashLocation" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( byte* )( params + 4 ) = InFiringMode;
				*( Vector* )( params + 8 ) = NewLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlashLocation( class Weapon* InWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClearFlashLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FlashLocationUpdated( class Weapon* InWeapon, Vector InFlashLocation, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FlashLocationUpdated" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( Vector* )( params + 4 ) = InFlashLocation;
				*( bool* )( params + 16 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponFired( class Weapon* InWeapon, bool bViaReplication, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.WeaponFired" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponStoppedFiring( class Weapon* InWeapon, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.WeaponStoppedFiring" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool BotFire( bool bFinished )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.BotFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bFinished;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanAttack( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CanAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TooCloseToAttack( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TooCloseToAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FireOnRelease(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FireOnRelease" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasRangedAttack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.HasRangedAttack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedToTurn( Vector targ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.NeedToTurn" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = targ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayTeleportEffect( bool bOut, bool bSound )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayTeleportEffect" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bOut;
				*( bool* )( params + 4 ) = bSound;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTeamChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.NotifyTeamChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PossessedBy( class Controller* C, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PossessedBy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = C;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateControllerOnPossess( bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.UpdateControllerOnPossess" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnPossessed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.UnPossessed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DropToGround(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.DropToGround" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RecommendLongRangedAttack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.RecommendLongRangedAttack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float RangedAttackTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.RangedAttackTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetWalking( bool bNewIsWalking )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetWalking" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewIsWalking;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanSplash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CanSplash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EndClimbLadder( class LadderVolume* OldLadder )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.EndClimbLadder" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LadderVolume** )( params + 0 ) = OldLadder;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClimbLadder( class LadderVolume* L )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClimbLadder" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LadderVolume** )( params + 0 ) = L;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			bool IsFirstPerson(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsFirstPerson" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ProcessViewRotation( float DeltaTime, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( Rotator* )( params + 4 ) = out_ViewRotation;
				*( Rotator* )( params + 16 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 4 );
				out_DeltaRot = *( Rotator* )( params + 16 );
			}

			void GetActorEyesViewPoint( Vector &out_Location, Rotator &out_Rotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetActorEyesViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = out_Location;
				*( Rotator* )( params + 12 ) = out_Rotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Location = *( Vector* )( params + 0 );
				out_Rotation = *( Rotator* )( params + 12 );
			}

			Vector GetPawnViewLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetPawnViewLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetWeaponStartTraceLocation( class Weapon* CurrentWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetWeaponStartTraceLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = CurrentWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool InFreeCam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.InFreeCam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Rotator GetAdjustedAimFor( class Weapon* W, Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetAdjustedAimFor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )( params + 0 ) = W;
				*( Vector* )( params + 4 ) = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void SetViewRotation( Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetViewRotation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMoveTarget( class Actor* NewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetMoveTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = NewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandlePickup( class Inventory* Inv )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.HandlePickup" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Inventory** )( params + 0 ) = Inv;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientMessage( ScriptArray< wchar_t > S, ScriptName Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClientMessage" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				*( ScriptName* )( params + 12 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OutsideWorldBounds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.OutsideWorldBounds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnCrouch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.UnCrouch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShouldCrouch( bool bCrouch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ShouldCrouch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bCrouch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndCrouch( float HeightAdjust )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.EndCrouch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = HeightAdjust;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartCrouch( float HeightAdjust )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.StartCrouch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = HeightAdjust;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandleMomentum( Vector Momentum, Vector HitLocation, ScriptClass* DamageType, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.HandleMomentum" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( Vector* )( params + 0 ) = Momentum;
				*( Vector* )( params + 12 ) = HitLocation;
				*( ScriptClass** )( params + 24 ) = DamageType;
				*( void** )( params + 28 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddVelocity( Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.AddVelocity" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( Vector* )( params + 0 ) = NewVelocity;
				*( Vector* )( params + 12 ) = HitLocation;
				*( ScriptClass** )( params + 24 ) = DamageType;
				*( void** )( params + 28 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KilledBy( class Pawn* EventInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.KilledBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = EventInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeFallingDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TakeFallingDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Restart(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Restart" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRestart(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClientRestart" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetRotation( Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClientSetRotation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePawnRotation( Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.UpdatePawnRotation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FaceRotation( Rotator NewRotation, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.FaceRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = NewRotation;
				*( float* )( params + 12 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool EncroachingOn( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.EncroachingOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EncroachedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.EncroachedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void gibbedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.gibbedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void JumpOffPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.JumpOffPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StuckOnPawn( class Pawn* OtherPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.StuckOnPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = OtherPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BaseChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.BaseChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanBeBaseForPawn( class Pawn* aPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CanBeBaseForPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = aPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CrushedBy( class Pawn* OtherPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CrushedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = OtherPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachFromController( bool bDestroyController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.DetachFromController" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bDestroyController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnDefaultController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SpawnDefaultController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceivedNewEvent( class SequenceEvent* Evt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ReceivedNewEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SequenceEvent** )( params + 0 ) = Evt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAssignController( class SeqAct_AssignController* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.OnAssignController" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_AssignController** )( params + 0 ) = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGiveInventory( class SeqAct_GiveInventory* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.OnGiveInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_GiveInventory** )( params + 0 ) = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Gasp(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Gasp" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMovementPhysics(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetMovementPhysics" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustDamage( int &InDamage, Vector &Momentum, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.AdjustDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = InDamage;
				*( Vector* )( params + 4 ) = Momentum;
				*( class Controller** )( params + 16 ) = InstigatedBy;
				*( Vector* )( params + 20 ) = HitLocation;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InDamage = *( int* )( params + 0 );
				Momentum = *( Vector* )( params + 4 );
			}

			bool HealDamage( int Amount, class Controller* Healer, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.HealDamage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = Amount;
				*( class Controller** )( params + 4 ) = Healer;
				*( ScriptClass** )( params + 8 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PruneDamagedBoneList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PruneDamagedBoneList" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TakeRadiusDamageOnBones( class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TakeRadiusDamageOnBones" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( class Controller** )( params + 0 ) = InstigatedBy;
				*( float* )( params + 4 ) = BaseDamage;
				*( float* )( params + 8 ) = DamageRadius;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( float* )( params + 16 ) = Momentum;
				*( Vector* )( params + 20 ) = HurtOrigin;
				*( bool* )( params + 32 ) = bFullDamage;
				*( class Actor** )( params + 36 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyTakeHit( class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.NotifyTakeHit" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Controller** )( params + 0 ) = InstigatedBy;
				*( Vector* )( params + 4 ) = HitLocation;
				*( int* )( params + 16 ) = Damage;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Controller* SetKillInstigator( class Controller* InstigatedBy, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetKillInstigator" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = InstigatedBy;
				*( ScriptClass** )( params + 4 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			void TakeDamage( int Damage, class Controller* InstigatedBy, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = Damage;
				*( class Controller** )( params + 4 ) = InstigatedBy;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			class TeamInfo* GetTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TeamInfo** )( params + function->return_val_offset() );
			}

			bool IsSameTeam( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsSameTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ThrowWeaponOnDeath(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ThrowWeaponOnDeath" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DelayTriggerDeath(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.DelayTriggerDeath" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Falling(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Falling" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Landed( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Landed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TickSpecial( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TickSpecial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HeadVolumeChange( class PhysicsVolume* newHeadVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.HeadVolumeChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicsVolume** )( params + 0 ) = newHeadVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BreathTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.BreathTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDrowningDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TakeDrowningDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDyingSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayDyingSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayHit( float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayHit" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( float* )( params + 0 ) = Damage;
				*( class Controller** )( params + 4 ) = InstigatedBy;
				*( Vector* )( params + 8 ) = HitLocation;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				*( void** )( params + 36 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TurnOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TurnOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDyingPhysics(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetDyingPhysics" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDying( ScriptClass* DamageType, Vector HitLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayDying" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = DamageType;
				*( Vector* )( params + 4 ) = HitLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TornOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TornOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFootStepSound( int FootDown )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayFootStepSound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = FootDown;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayLanded( float ImpactVel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayLanded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = ImpactVel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Vehicle* GetVehicleBase(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetVehicleBase" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Vehicle** )( params + function->return_val_offset() );
			}

			void Suicide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Suicide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartDriving( class Vehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.StartDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopDriving( class Vehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.StopDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDefaultInventory(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.AddDefaultInventory" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawHUD( class HUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.DrawHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )( params + 0 ) = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ThrowActiveWeapon( bool bDestroyWeap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ThrowActiveWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bDestroyWeap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TossInventory( class Inventory* Inv, Vector ForceVelocity )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.TossInventory" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Inventory** )( params + 0 ) = Inv;
				*( Vector* )( params + 4 ) = ForceVelocity;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActiveWeapon( class Weapon* NewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetActiveWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = NewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayWeaponSwitch( class Weapon* OldWeapon, class Weapon* NewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.PlayWeaponSwitch" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )( params + 0 ) = OldWeapon;
				*( class Weapon** )( params + 4 ) = NewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetCollisionRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetCollisionRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool IsStationary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IsStationary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SpawnedByKismet(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SpawnedByKismet" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoKismetAttachment( class Actor* Attachment, class SeqAct_AttachToActor* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.DoKismetAttachment" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = Attachment;
				*( class SeqAct_AttachToActor** )( params + 4 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetDamageScaling(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.GetDamageScaling" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void OnSetMaterial( class SeqAct_SetMaterial* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.OnSetMaterial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetMaterial** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTeleport( class SeqAct_Teleport* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.OnTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Teleport** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MessagePlayer( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.MessagePlayer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BecomeViewTarget( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.BecomeViewTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SoakPause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SoakPause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearConstraints(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClearConstraints" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddPathConstraint( class PathConstraint* Constraint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.AddPathConstraint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PathConstraint** )( params + 0 ) = Constraint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddGoalEvaluator( class PathGoalEvaluator* Evaluator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.AddGoalEvaluator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PathGoalEvaluator** )( params + 0 ) = Evaluator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PathConstraint* CreatePathConstraint( ScriptClass* ConstraintClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CreatePathConstraint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = ConstraintClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PathConstraint** )( params + function->return_val_offset() );
			}

			void IncrementPathStep( int Cnt, class Canvas* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IncrementPathStep" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = Cnt;
				*( class Canvas** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementPathChild( int Cnt, class Canvas* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.IncrementPathChild" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = Cnt;
				*( class Canvas** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawPathStep( class Canvas* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.DrawPathStep" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearPathStep(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ClearPathStep" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ZeroMovementVariables(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.ZeroMovementVariables" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCinematicMode( bool bInCinematicMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetCinematicMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bInCinematicMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRootMotionInterpCurrentTime( float inTime, float DeltaTime, bool bUpdateSkelPose )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.SetRootMotionInterpCurrentTime" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = inTime;
				*( float* )( params + 4 ) = DeltaTime;
				*( bool* )( params + 8 ) = bUpdateSkelPose;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Speak( class SoundCue* Cue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.Speak" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SoundCue** )( params + 0 ) = Cue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetVelocity( class SeqAct_SetVelocity* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.OnSetVelocity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetVelocity** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckClotheslineDamage( class Pawn* PawnHittingMe )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Pawn.CheckClotheslineDamage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = PawnHittingMe;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
