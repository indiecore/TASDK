#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Weapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Weapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Weapon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Weapon : public Inventory
	{
	public:
			ADD_VAR( ::BoolProperty, bInstantHit, 0x10 )
			float GetTraceRange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetTraceRange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, WeaponRange, 0xFFFFFFFF )
			bool HasAnyAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.HasAnyAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetAIRating(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetAIRating" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetWeaponRating(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetWeaponRating" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool TryPutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.TryPutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool DenyClientWeaponSet(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.DenyClientWeaponSet" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, CurrentFireMode, 0xFFFFFFFF )
			bool CanAttack( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.CanAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FireOnRelease(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.FireOnRelease" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.IsFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanThrow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.CanThrow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, CachedMaxRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AIRating, 0xFFFFFFFF )
			ADD_OBJECT( AIController, AIController )
			ADD_VAR( ::FloatProperty, Priority, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultAnimSpeed, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bMeleeWeapon, 0x20 )
			ADD_VAR( ::BoolProperty, bWasDoNotActivate, 0x8 )
			ADD_VAR( ::BoolProperty, bWasOptionalSet, 0x4 )
			ADD_VAR( ::BoolProperty, bCanThrow, 0x2 )
			ADD_VAR( ::BoolProperty, bWeaponPutDown, 0x1 )
			ADD_STRUCT( ::VectorProperty, FireOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PutDownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EquipTime, 0xFFFFFFFF )
			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ItemRemovedFromInvManager(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ItemRemovedFromInvManager" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HolderDied(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.HolderDied" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DoOverrideNextWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.DoOverrideNextWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool DoOverridePrevWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.DoOverridePrevWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DropFrom( Vector StartLocation, Vector StartVelocity )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.DropFrom" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = StartLocation;
				*( Vector* )( params + 12 ) = StartVelocity;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWeaponThrown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ClientWeaponThrown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void GetWeaponDebug(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetWeaponDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetPendingFireLength(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetPendingFireLength" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool PendingFire( int FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.PendingFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ConsumeAmmo( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ConsumeAmmo" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int AddAmmo( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.AddAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool HasAmmo( byte FireModeNum, int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.HasAmmo" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				*( int* )( params + 4 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetPendingFire( int FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.SetPendingFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearPendingFire( int FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ClearPendingFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* GetProjectileClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetProjectileClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			Rotator AddSpread( Rotator BaseAim )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.AddSpread" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = BaseAim;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			float MaxRange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.MaxRange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			class AnimNodeSequence* GetWeaponAnimNodeSeq(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetWeaponAnimNodeSeq" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimNodeSequence** )( params + function->return_val_offset() );
			}

			void PlayWeaponAnimation( ScriptName Sequence, float fDesiredDuration, bool bLoop )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.PlayWeaponAnimation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = Sequence;
				*( float* )( params + 8 ) = fDesiredDuration;
				*( bool* )( params + 12 ) = bLoop;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopWeaponAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.StopWeaponAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFireEffects( byte FireModeNum, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.PlayFireEffects" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopFireEffects( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.StopFireEffects" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetFireInterval( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetFireInterval" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void TimeWeaponFiring( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.TimeWeaponFiring" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefireCheckTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.RefireCheckTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TimeWeaponPutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.TimeWeaponPutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TimeWeaponEquipping(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.TimeWeaponEquipping" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Activate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.Activate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PutDownWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.PutDownWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DenyPickupQuery( ScriptClass* ItemClass, class Actor* Pickup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.DenyPickupQuery" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = ItemClass;
				*( class Actor** )( params + 4 ) = Pickup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void WeaponEmpty(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.WeaponEmpty" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementFlashCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.IncrementFlashCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlashCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ClearFlashCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFlashLocation( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.SetFlashLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlashLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ClearFlashLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachWeaponTo( ScriptName SocketName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.AttachWeaponTo" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 4 ) = SocketName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.DetachWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientGivenTo( class Pawn* NewOwner, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ClientGivenTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = NewOwner;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWeaponSet( bool bOptionalSet, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ClientWeaponSet" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bOptionalSet;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerStartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ServerStartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.BeginFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.StopFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerStopFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ServerStopFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.EndFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceEndFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ForceEndFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendToFiringState( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.SendToFiringState" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCurrentFireMode( byte FiringModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.SetCurrentFireMode" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FiringModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireModeUpdated( byte FiringMode, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.FireModeUpdated" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = FiringMode;
				*( bool* )( params + 4 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireAmmunition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.FireAmmunition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Rotator GetAdjustedAim( Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetAdjustedAim" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			class Actor* GetTraceOwner(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetTraceOwner" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void* CalcWeaponFire( Vector StartTrace, Vector EndTrace, Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.CalcWeaponFire" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )( params + 0 ) = StartTrace;
				*( Vector* )( params + 12 ) = EndTrace;
				*( Vector* )( params + 36 ) = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool PassThroughDamage( class Actor* HitActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.PassThroughDamage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = HitActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void InstantFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.InstantFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessInstantHit( byte FiringMode, void* Impact, int NumHits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ProcessInstantHit" );
				byte *params = ( byte* )( malloc( 85 ) );
				*( byte* )( params + 0 ) = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( int* )( params + 84 ) = NumHits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Projectile* ProjectileFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ProjectileFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Projectile** )( params + function->return_val_offset() );
			}

			void CustomFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.CustomFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetMuzzleLoc(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetMuzzleLoc" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetPhysicalFireStartLoc( Vector AimDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetPhysicalFireStartLoc" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = AimDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void HandleFinishedFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.HandleFinishedFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyWeaponFired( byte FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.NotifyWeaponFired" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyWeaponFinishedFiring( byte FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.NotifyWeaponFinishedFiring" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldRefire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.ShouldRefire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool StillFiring( byte FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.StillFiring" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void WeaponIsDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.WeaponIsDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CacheAIController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.CacheAIController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetTargetDistance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Weapon.GetTargetDistance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
