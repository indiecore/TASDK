#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTWeapon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTWeapon : public UDKWeapon
	{
	public:
			int GetAmmoCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetAmmoCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, AmmoDisplayType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, InventoryGroup, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, UseHintString, 0xFFFFFFFF )
			bool CoversScreenSpace( Vector ScreenLoc, class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CoversScreenSpace" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = ScreenLoc;
				*( class Canvas** )( params + 12 ) = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetPowerPerc(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetPowerPerc" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float DesireAmmo( bool bDetour )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DesireAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDetour;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bExportMenuData, 0x1 )
			void ServerStartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ServerStartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bAllowFiringWithoutController, 0x40000 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bSmallWeapons, 0x8 )
			ADD_VAR( ::BoolProperty, bUseCustomCoordinates, 0x4 )
			void AdjustWeaponTimingForConsole(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.AdjustWeaponTimingForConsole" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateOverlayMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CreateOverlayMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF )
			void CalcInventoryWeight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CalcInventoryWeight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, InventoryWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroupWeight, 0xFFFFFFFF )
			bool ShouldSwitchTo( class UTWeapon* InWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ShouldSwitchTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTWeapon** )params = InWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetSkin( class Material* NewMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SetSkin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Material** )params = NewMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActiveRenderOverlays( class HUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ActiveRenderOverlays" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )params = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawWeaponCrosshair( class HUD* HUD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DrawWeaponCrosshair" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )params = HUD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, CrosshairScaling, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, CrosshairImage )
			void DrawLockedOn( class HUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DrawLockedOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )params = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bWasLocked, 0x2 )
			ADD_VAR( ::FloatProperty, LockedStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentLockedScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StartLockedScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LockedScaleTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FinalLockedScale, 0xFFFFFFFF )
			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			ADD_VAR( ::FloatProperty, ZoomedRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoomedTargetFOV, 0xFFFFFFFF )
			float GetFireInterval( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetFireInterval" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PlayArmAnimation( ScriptName Sequence, float fDesiredDuration, bool OffHand, bool bLoop )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PlayArmAnimation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )params = Sequence;
				*( float* )( params + 8 ) = fDesiredDuration;
				*( bool* )( params + 12 ) = OffHand;
				*( bool* )( params + 16 ) = bLoop;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( AnimSet, ArmsAnimSet )
			void PlayWeaponAnimation( ScriptName Sequence, float fDesiredDuration, bool bLoop )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PlayWeaponAnimation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = Sequence;
				*( float* )( params + 8 ) = fDesiredDuration;
				*( bool* )( params + 12 ) = bLoop;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFireEffects( byte FireModeNum, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PlayFireEffects" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = FireModeNum;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopFireEffects( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.StopFireEffects" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShakeView(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ShakeView" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ForceFeedbackWaveform, WeaponFireWaveForm )
			void WeaponCalcCamera( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.WeaponCalcCamera" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )params = fDeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
			}

			void WeaponPlaySound( class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.WeaponPlaySound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SoundCue** )params = Sound;
				*( float* )( params + 4 ) = NoiseLoudness;
				*( bool* )( params + 8 ) = bStopWhenOwnerDestroyed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bSuppressSounds, 0x40 )
			void PlayFiringSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PlayFiringSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MuzzleFlashTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.MuzzleFlashTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bMuzzleFlashPSCLoops, 0x400 )
			void CauseMuzzleFlashLight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CauseMuzzleFlashLight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, MuzzleFlashLightClass )
			ADD_VAR( ::NameProperty, MuzzleFlashSocket, 0xFFFFFFFF )
			void CauseMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CauseMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bShowAltMuzzlePSCWhenWeaponHidden, 0x200 )
			ADD_OBJECT( ParticleSystem, MuzzleFlashAltPSCTemplate )
			ADD_VAR( ::BoolProperty, bMuzzleFlashAttached, 0x800 )
			ADD_OBJECT( ParticleSystem, MuzzleFlashPSCTemplate )
			ADD_VAR( ::FloatProperty, MuzzleFlashDuration, 0xFFFFFFFF )
			void StopMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.StopMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TimeWeaponPutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.TimeWeaponPutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayWeaponPutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PlayWeaponPutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::NameProperty, WeaponPutDownAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ArmsPutDownAnim, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, WeaponPutDownSnd )
			void TimeWeaponEquipping(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.TimeWeaponEquipping" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetEquipTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetEquipTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PlayWeaponEquip(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PlayWeaponEquip" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::NameProperty, WeaponEquipAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ArmsEquipAnim, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, WeaponEquipSnd )
			void AttachWeaponTo( ScriptName SocketName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.AttachWeaponTo" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 4 ) = SocketName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bPendingShow, 0x100 )
			ADD_OBJECT( ScriptClass, AttachmentClass )
			void SetMuzzleFlashParams(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SetMuzzleFlashParams" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.AttachMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DetachWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DetachMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeVisibility( bool bIsVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ChangeVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIsVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PerformWeaponChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PerformWeaponChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetViewAxes( Vector &XAxis, Vector &YAxis, Vector &ZAxis )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetViewAxes" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( Vector* )params = XAxis;
				*( Vector* )( params + 12 ) = YAxis;
				*( Vector* )( params + 24 ) = ZAxis;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				XAxis = *( Vector* )params;
				YAxis = *( Vector* )( params + 12 );
				ZAxis = *( Vector* )( params + 24 );
			}

			void ServerReselectWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ServerReselectWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanThrow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CanThrow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte GetHand(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetHand" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void SetPosition( class UDKPawn* Holder, float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SetPosition" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UDKPawn** )params = Holder;
				*( float* )( params + 4 ) = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bForceHidden, 0x200000 )
			ADD_STRUCT( ::VectorProperty, HiddenWeaponsOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PlayerViewOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SmallWeaponsOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WideScreenOffsetScaling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BobDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, JumpDamping, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LastRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxYawLag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxPitchLag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastRotUpdate, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, WidescreenRotationOffset, 0xFFFFFFFF )
			bool ShouldLagRot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ShouldLagRot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int LagRot( int NewValue, int LastValue, float MaxDiff, int Index, float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.LagRot" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = NewValue;
				*( int* )( params + 4 ) = LastValue;
				*( float* )( params + 8 ) = MaxDiff;
				*( int* )( params + 12 ) = Index;
				*( float* )( params + 16 ) = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, OldRotDiff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldLeadMag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldMaxDiff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotChgSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ReturnChgSpeed, 0xFFFFFFFF )
			void AdjustPlayerDamage( int &Damage, class Controller* InstigatedBy, Vector HitLocation, Vector &Momentum, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.AdjustPlayerDamage" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( int* )params = Damage;
				*( class Controller** )( params + 4 ) = InstigatedBy;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Damage = *( int* )params;
				Momentum = *( Vector* )( params + 20 );
			}

			float RelativeStrengthVersus( class Pawn* P, float Dist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.RelativeStrengthVersus" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = P;
				*( float* )( params + 4 ) = Dist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetWeaponRating(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetWeaponRating" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, CurrentRating, 0xFFFFFFFF )
			bool CanAttack( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CanAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float BotDesireability( class Actor* PickupHolder, class Pawn* P, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.BotDesireability" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Actor** )params = PickupHolder;
				*( class Pawn** )( params + 4 ) = P;
				*( class Controller** )( params + 8 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool AmmoMaxed( int Mode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.AmmoMaxed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Mode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( ScriptClass, AmmoPickupClass )
			ADD_VAR( ::IntProperty, MaxAmmoCount, 0xFFFFFFFF )
			float GetDamageRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetDamageRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool CanHeal( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CanHeal" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetOptimalRangeFor( class Actor* Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetOptimalRangeFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool FireOnRelease(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.FireOnRelease" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FocusOnLeader( bool bLeaderFiring )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.FocusOnLeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bLeaderFiring;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RecommendRangedAttack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.RecommendRangedAttack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float SuggestAttackStyle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SuggestAttackStyle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float SuggestDefenseStyle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SuggestDefenseStyle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float RangedAttackTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.RangedAttackTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool SplashJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SplashJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bSplashJump, 0x1000 )
			bool ShouldFireWithoutTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ShouldFireWithoutTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte BestMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.BestMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool IsFullyCharged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.IsFullyCharged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadyToFire( bool bFinished )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ReadyToFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bFinished;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool StillFiring( byte FireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.StillFiring" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ConsumeAmmo( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ConsumeAmmo" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int AddAmmo( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.AddAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool HasAmmo( byte FireModeNum, int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.HasAmmo" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = FireModeNum;
				*( int* )( params + 4 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasAnyAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.HasAnyAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.NeedAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Loaded( bool bUseWeaponMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.Loaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bUseWeaponMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DenyPickupQuery( ScriptClass* ItemClass, class Actor* Pickup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DenyPickupQuery" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = ItemClass;
				*( class Actor** )( params + 4 ) = Pickup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void WeaponEmpty(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.WeaponEmpty" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool bReadyToFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.bReadyToFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector InstantFireStartTrace(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.InstantFireStartTrace" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector InstantFireEndTrace( Vector StartTrace )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.InstantFireEndTrace" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = StartTrace;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void InstantFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.InstantFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bUsingAimingHelp, 0x20000 )
			void* InstantAimHelp( Vector StartTrace, Vector EndTrace, void* RealImpact )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.InstantAimHelp" );
				byte *params = ( byte* )( malloc( 104 ) );
				*( Vector* )params = StartTrace;
				*( Vector* )( params + 12 ) = EndTrace;
				*( void** )( params + 24 ) = RealImpact;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, AimingHelpRadius, 0xFFFFFFFF )
			class Projectile* ProjectileFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ProjectileFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Projectile** )( params + function->return_val_offset() );
			}

			void ProcessInstantHit( byte FiringMode, void* Impact, int NumHits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ProcessInstantHit" );
				byte *params = ( byte* )( malloc( 85 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( int* )( params + 84 ) = NumHits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetZoomedState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetZoomedState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool CheckZoom( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CheckZoom" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, ZoomedFireModeNum, 0xFFFFFFFF )
			void StartZoom( class UTPlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.StartZoom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( SoundCue, ZoomInSound )
			void EndZoom( class UTPlayerController* PC, bool bReturningTo3P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.EndZoom" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerController** )params = PC;
				*( bool* )( params + 4 ) = bReturningTo3P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( SoundCue, ZoomOutSound )
			void ClientEndFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ClientEndFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.EndFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendToFiringState( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SendToFiringState" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWeaponSet( bool bOptionalSet, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ClientWeaponSet" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bOptionalSet;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireAmmunition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.FireAmmunition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, SwitchAbortTime, 0xFFFFFFFF )
			void PreloadTextures( bool bForcePreload )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.PreloadTextures" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForcePreload;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowSwitchTo( class Weapon* NewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.AllowSwitchTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )params = NewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TryPutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.TryPutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FiringPutDownWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.FiringPutDownWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetPhysicalFireStartLoc( Vector AimDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetPhysicalFireStartLoc" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = AimDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, ProjectileSpawnOffset, 0xFFFFFFFF )
			Vector GetEffectLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetEffectLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void RefireCheckTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.RefireCheckTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupArmsAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SetupArmsAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class AnimNodeSequence* GetArmAnimNodeSeq(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.GetArmAnimNodeSeq" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class AnimNodeSequence** )( params + function->return_val_offset() );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetWeaponOverlayFlags( class UTPawn* OwnerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.SetWeaponOverlayFlags" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )params = OwnerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float DetourWeight( class Pawn* Other, float PathWeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DetourWeight" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = Other;
				*( float* )( params + 4 ) = PathWeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool RecommendLongRangedAttack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.RecommendLongRangedAttack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ThrottleLook( float &aTurn, float &aLookUp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ThrottleLook" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = aTurn;
				*( float* )( params + 4 ) = aLookUp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				aTurn = *( float* )params;
				aLookUp = *( float* )( params + 4 );
			}

			void Activate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.Activate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DropFrom( Vector StartLocation, Vector StartVelocity )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DropFrom" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = StartLocation;
				*( Vector* )( params + 12 ) = StartVelocity;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWeaponThrown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.ClientWeaponThrown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanViewAccelerationWhenFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.CanViewAccelerationWhenFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void HolderEnteredVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.HolderEnteredVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HolderExitedVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.HolderExitedVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, WeaponCanvasXPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WeaponCanvasYPct, 0xFFFFFFFF )
			void DrawKillIcon( class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.DrawKillIcon" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Canvas** )params = Canvas;
				*( float* )( params + 4 ) = ScreenX;
				*( float* )( params + 8 ) = ScreenY;
				*( float* )( params + 12 ) = HUDScaleX;
				*( float* )( params + 16 ) = HUDScaleY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool EnableFriendlyWarningCrosshair(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeapon.EnableFriendlyWarningCrosshair" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bSuperWeapon, 0x10 )
			ADD_VAR( ::BoolProperty, bNeverForwardPendingFire, 0x20 )
			ADD_VAR( ::BoolProperty, bUsesOffhand, 0x80 )
			ADD_VAR( ::BoolProperty, bRecommendSplashDamage, 0x2000 )
			ADD_VAR( ::BoolProperty, bSniping, 0x4000 )
			ADD_VAR( ::BoolProperty, bFastRepeater, 0x8000 )
			ADD_VAR( ::BoolProperty, bLockedAimWhileFiring, 0x10000 )
			ADD_VAR( ::BoolProperty, bTargetFrictionEnabled, 0x80000 )
			ADD_VAR( ::BoolProperty, bTargetAdhesionEnabled, 0x100000 )
			ADD_VAR( ::BoolProperty, bHasLocationSpeech, 0x400000 )
			ADD_VAR( ::IntProperty, LockerAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconWidth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DroppedPickupOffsetZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoomFadeTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PivotTranslation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LockerRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LockerOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aimerror, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoomedTurnSpeedScalePct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionDistanceMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionDistancePeak, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionDistanceMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionPeakRadiusScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionPeakHeightScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetFrictionOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionZoomedBoostValue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionTimeMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionDistanceMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionAimDistY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionAimDistZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionScaleAmountMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionTargetVelocityMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionPlayerVelocityMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionZoomedBoostValue, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
