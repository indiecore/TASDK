#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PhysicsVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PhysicsVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PhysicsVolume." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PhysicsVolume : public Volume
	{
	public:
			ADD_VAR( ::BoolProperty, bPainCausing, 0x2 )
			ADD_VAR( ::FloatProperty, DamagePerSec, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWaterVolume, 0x1000 )
			ADD_OBJECT( PhysicsVolume, NextPhysicsVolume )
			ADD_OBJECT( Controller, DamageInstigator )
			ADD_OBJECT( Info, PainTimer )
			ADD_VAR( ::FloatProperty, MaxDampingForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RigidBodyDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PainInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FluidFriction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Priority, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, DamageType )
			ADD_VAR( ::FloatProperty, TerminalVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroundFriction, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPhysicsOnContact, 0x800 )
			ADD_VAR( ::BoolProperty, bCrowdAgentsPlayDeathAnim, 0x400 )
			ADD_VAR( ::BoolProperty, bNeutralZone, 0x200 )
			ADD_VAR( ::BoolProperty, bBounceVelocity, 0x100 )
			ADD_VAR( ::BoolProperty, bMoveProjectiles, 0x80 )
			ADD_VAR( ::BoolProperty, bNoInventory, 0x40 )
			ADD_VAR( ::BoolProperty, bDestructive, 0x20 )
			ADD_VAR( ::BoolProperty, BACKUP_bPainCausing, 0x10 )
			ADD_VAR( ::BoolProperty, bEntryPain, 0x8 )
			ADD_VAR( ::BoolProperty, bAIShouldIgnorePain, 0x4 )
			ADD_VAR( ::BoolProperty, bVelocityAffectsWalking, 0x1 )
			ADD_STRUCT( ::VectorProperty, ZoneVelocity, 0xFFFFFFFF )
			float GetGravityZ(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.GetGravityZ" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Vector GetZoneVelocityForActor( class Actor* TheActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.GetZoneVelocityForActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = TheActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PhysicsChangedFor( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.PhysicsChangedFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActorEnteredVolume( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.ActorEnteredVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActorLeavingVolume( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.ActorLeavingVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnEnteredVolume( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.PawnEnteredVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnLeavingVolume( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.PawnLeavingVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggle( class SeqAct_Toggle* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )( params + 0 ) = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CollisionChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.CollisionChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TimerPop( class VolumeTimer* T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.TimerPop" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class VolumeTimer** )( params + 0 ) = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )( params + 0 ) = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CausePainTo( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.CausePainTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ModifyPlayer( class Pawn* PlayerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.ModifyPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = PlayerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyPawnBecameViewTarget( class Pawn* P, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.NotifyPawnBecameViewTarget" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( class PlayerController** )( params + 4 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetDamageInstigator( class SeqAct_SetDamageInstigator* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.OnSetDamageInstigator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetDamageInstigator** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldSaveForCheckpoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.ShouldSaveForCheckpoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )( params + 0 );
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicsVolume.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )( params + 0 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
