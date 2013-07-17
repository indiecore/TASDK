#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SVehicle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SVehicle : public Vehicle
	{
	public:
			ADD_VAR( ::FloatProperty, RadialImpulseScaling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngErrorAccumulator, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DriverViewYaw, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DriverViewPitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CamDist, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, BaseOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumPoweredWheels, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForwardVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OutputRise, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OutputSteering, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OutputGas, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OutputBrake, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastCollisionSoundTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EngineStopOffsetSecs, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EngineStartOffsetSecs, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LatAngleVolumeMult, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SquealLatThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SquealThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CollisionIntervalSecs, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, ExitVehicleSound )
			ADD_OBJECT( SoundCue, EnterVehicleSound )
			ADD_OBJECT( SoundCue, CollisionSound )
			ADD_VAR( ::FloatProperty, UprightStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UprightTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UprightTorqueStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UprightLiftStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeOffGround, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxAngularVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeavySuspensionShiftPercent, 0xFFFFFFFF )
			ADD_OBJECT( RB_ConstraintInstance, StayUprightConstraintInstance )
			ADD_OBJECT( RB_StayUprightSetup, StayUprightConstraintSetup )
			ADD_VAR( ::FloatProperty, StayUprightDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StayUprightStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StayUprightPitchResistAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StayUprightRollResistAngle, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHoldingDownHandbrake, 0x1000 )
			ADD_VAR( ::BoolProperty, bOutputHandbrake, 0x800 )
			ADD_VAR( ::BoolProperty, bIsUprighting, 0x400 )
			ADD_VAR( ::BoolProperty, bFlipRight, 0x200 )
			ADD_VAR( ::BoolProperty, bCanFlip, 0x100 )
			ADD_VAR( ::BoolProperty, bWasChassisTouchingGroundLastTick, 0x80 )
			ADD_VAR( ::BoolProperty, bChassisTouchingGround, 0x40 )
			ADD_VAR( ::BoolProperty, bIsInverted, 0x20 )
			ADD_VAR( ::BoolProperty, bVehicleOnWater, 0x10 )
			ADD_VAR( ::BoolProperty, bVehicleOnGround, 0x8 )
			ADD_VAR( ::BoolProperty, bUpdateWheelShapes, 0x4 )
			ADD_VAR( ::BoolProperty, bUseSuspensionAxis, 0x2 )
			ADD_VAR( ::BoolProperty, bStayUpright, 0x1 )
			ADD_STRUCT( ::VectorProperty, InertiaTensorMultiplier, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, COMOffset, 0xFFFFFFFF )
			void AddForce( Vector Force )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.AddForce" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Force;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddImpulse( Vector Impulse )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.AddImpulse" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Impulse;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddTorque( Vector Torque )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.AddTorque" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Torque;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsSleeping(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.IsSleeping" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetWheelCollision( int WheelNum, bool bCollision )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.SetWheelCollision" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = WheelNum;
				*( bool* )( params + 4 ) = bCollision;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TurnOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.TurnOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopVehicleSounds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.StopVehicleSounds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeRadiusDamage( class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.TakeRadiusDamage" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Controller** )( params + 0 ) = InstigatedBy;
				*( float* )( params + 4 ) = BaseDamage;
				*( float* )( params + 8 ) = DamageRadius;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( float* )( params + 16 ) = Momentum;
				*( Vector* )( params + 20 ) = HurtOrigin;
				*( bool* )( params + 32 ) = bFullDamage;
				*( class Actor** )( params + 36 ) = DamageCauser;
				*( float* )( params + 40 ) = DamageFalloffExponent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitVehicleRagdoll( class SkeletalMesh* RagdollMesh, class PhysicsAsset* RagdollPhysAsset, Vector ActorMove, bool bClearAnimTree )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.InitVehicleRagdoll" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class SkeletalMesh** )( params + 0 ) = RagdollMesh;
				*( class PhysicsAsset** )( params + 4 ) = RagdollPhysAsset;
				*( Vector* )( params + 8 ) = ActorMove;
				*( bool* )( params + 20 ) = bClearAnimTree;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddVelocity( Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.AddVelocity" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( Vector* )( params + 0 ) = NewVelocity;
				*( Vector* )( params + 12 ) = HitLocation;
				*( ScriptClass** )( params + 24 ) = DamageType;
				*( void** )( params + 28 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Died( class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.Died" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CalcCamera( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.CalcCamera" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )( params + 0 ) = fDeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				*( float* )( params + 28 ) = out_FOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
				out_FOV = *( float* )( params + 28 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetDefaultCameraMode( class PlayerController* RequestedBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.GetDefaultCameraMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = RequestedBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool TryToDrive( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.TryToDrive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasWheelsOnGround(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.HasWheelsOnGround" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StartEngineSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.StartEngineSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartEngineSoundTimed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.StartEngineSoundTimed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopEngineSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.StopEngineSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopEngineSoundTimed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.StopEngineSoundTimed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehiclePlayEnterSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.VehiclePlayEnterSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehiclePlayExitSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.VehiclePlayExitSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrivingStatusChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.DrivingStatusChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RigidBodyCollision( void* &RigidCollisionData, int ContactIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.RigidBodyCollision" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 8 ) = RigidCollisionData;
				*( int* )( params + 44 ) = ContactIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				RigidCollisionData = *( void** )( params + 8 );
			}

			void SuspensionHeavyShift( float Delta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.SuspensionHeavyShift" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Delta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostTeleport( class Teleporter* OutTeleporter )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.PostTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Teleporter** )( params + 0 ) = OutTeleporter;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void DisplayWheelsDebug( class HUD* HUD, float YL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.DisplayWheelsDebug" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = YL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float HermiteEval( float Slip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.HermiteEval" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = Slip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void GetSVehicleDebug(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SVehicle.GetSVehicleDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
