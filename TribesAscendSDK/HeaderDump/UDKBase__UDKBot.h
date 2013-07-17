#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKBot." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKBot." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKBot." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKBot : public AIController
	{
	public:
			ADD_VAR( ::FloatProperty, MultiJumpZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DodgeToGoalPct, 0xFFFFFFFF )
			ADD_OBJECT( Actor, FearSpots )
			ADD_VAR( ::FloatProperty, DodgeLandZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentAimError, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastErrorUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ErrorUpdateFrequency, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastAimUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AimUpdateFrequency, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastIterativeCheck, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, BlockedAimTarget )
			ADD_OBJECT( NavigationPoint, SquadRouteGoal )
			ADD_STRUCT( ::VectorProperty, TrackedVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseTrackingReactionTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TrackingReactionTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastSeenTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastSeeingPos, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastSeenPos, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MonitorMaxDistSq, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, MonitoredPawn )
			ADD_STRUCT( ::VectorProperty, MonitorStartLoc, 0xFFFFFFFF )
			ADD_OBJECT( Projectile, WarningProjectile )
			ADD_VAR( ::FloatProperty, WarningDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RespawnPredictionTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HearingThreshold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AcquisitionYawRate, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ImpactVelocity, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, CurrentlyTrackedEnemy )
			ADD_OBJECT( Vehicle, LastBlockingVehicle )
			ADD_OBJECT( Pawn, VisibleEnemy )
			ADD_VAR( ::FloatProperty, EnemyVisibilityTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ScriptedFireMode, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUsePreviousSquadRoute, 0x4000 )
			ADD_VAR( ::BoolProperty, bUsingSquadRoute, 0x2000 )
			ADD_VAR( ::BoolProperty, bAllowRouteReuse, 0x1000 )
			ADD_VAR( ::BoolProperty, bNeedDelayedLeaveVehicle, 0x800 )
			ADD_VAR( ::BoolProperty, bEnemyAcquired, 0x400 )
			ADD_VAR( ::BoolProperty, bInDodgeMove, 0x200 )
			ADD_VAR( ::BoolProperty, bPlannedJump, 0x100 )
			ADD_VAR( ::BoolProperty, bJumpOverWall, 0x80 )
			ADD_VAR( ::BoolProperty, bLeadTarget, 0x40 )
			ADD_VAR( ::BoolProperty, bEnemyIsVisible, 0x20 )
			ADD_VAR( ::BoolProperty, bEnemyInfoValid, 0x10 )
			ADD_VAR( ::BoolProperty, bTargetAlternateLoc, 0x8 )
			ADD_VAR( ::BoolProperty, bForceRefreshRoute, 0x4 )
			ADD_VAR( ::BoolProperty, bScriptSpecialJumpCost, 0x2 )
			ADD_VAR( ::BoolProperty, bExecutingWhatToDoNext, 0x1 )
			ADD_OBJECT( Actor, TemporaryFocus )
			ADD_OBJECT( UDKSquadAI, Squad )
			class Actor* FaceActor( float StrafingModifier )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.FaceActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = StrafingModifier;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void ExecuteWhatToDoNext(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.ExecuteWhatToDoNext" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveRunOverWarning( class UDKVehicle* V, float projSpeed, Vector VehicleDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.ReceiveRunOverWarning" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class UDKVehicle** )( params + 0 ) = V;
				*( float* )( params + 4 ) = projSpeed;
				*( Vector* )( params + 8 ) = VehicleDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WaitToSeeEnemy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.WaitToSeeEnemy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LatentWhatToDoNext(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.LatentWhatToDoNext" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanMakePathTo( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.CanMakePathTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Actor* FindBestInventoryPath( float &MinWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.FindBestInventoryPath" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = MinWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MinWeight = *( float* )( params + 0 );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			class Actor* FindPathToSquadRoute( bool bWeightDetours )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.FindPathToSquadRoute" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWeightDetours;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void BuildSquadRoute(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.BuildSquadRoute" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* FindBestSuperPickup( float MaxDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.FindBestSuperPickup" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = MaxDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void WhatToDoNext(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.WhatToDoNext" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MonitoredPawnAlert(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.MonitoredPawnAlert" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TimeDJReset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.TimeDJReset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MayDodgeToMoveTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.MayDodgeToMoveTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SpecialJumpCost( float RequiredJumpZ, float &Cost )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.SpecialJumpCost" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = RequiredJumpZ;
				*( float* )( params + 4 ) = Cost;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Cost = *( float* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			float SuperDesireability( class PickupFactory* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.SuperDesireability" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PickupFactory** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float AdjustAimError( float TargetDist, bool bInstantProj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.AdjustAimError" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = TargetDist;
				*( bool* )( params + 4 ) = bInstantProj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void MissedDodge(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.MissedDodge" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DelayedWarning(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.DelayedWarning" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DelayedLeaveVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKBot.DelayedLeaveVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
