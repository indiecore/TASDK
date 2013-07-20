#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDevice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDevice." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDevice." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice : public UTWeapon
	{
	public:
			ADD_VAR( ::IntProperty, m_nCarriedAmmo, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nIconIndex, 0xFFFFFFFF )
			float CalcHUDAimChargePercent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CalcHUDAimChargePercent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::StrProperty, UpgradeDescription, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBXPActivityId, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, InfoPanelDescription, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, InfoPanelDamage, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, InfoPanelRadius, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, InfoPanelFireRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, InfoPanelClipSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBWeaponId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nReticuleIndex, 0xFFFFFFFF )
			float GetAccuracy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetAccuracy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_bAllowFireWhileZoomed, 0x100000 )
			ADD_STRUCT( ::VectorProperty, m_vClientSideFireOffset, 0xFFFFFFFF )
			ADD_OBJECT( TrDeviceContentData, m_ContentData )
			ADD_VAR( ::StrProperty, m_sContentDataClassName, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_TinyWeaponsOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeBeforeInactiveReload, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastActiveTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nTetherCounter, 0xFFFFFFFF )
			ADD_OBJECT( AnimSet, m_NoAmmoAnimSet )
			ADD_VAR( ::FloatProperty, m_fFireIntervalForLastShotInClip, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClientSideHitLeeway, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_ZoomOverlayMaterial )
			ADD_VAR( ::NameProperty, m_nmZoomMaterialEffectName, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vZoomMeshOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fZoomRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDesiredZoomFOV, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_ShotsFired, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vPositionPivotOffset, 0xFFFFFFFF )
			ADD_OBJECT( CameraShake, m_FireCameraShake )
			ADD_OBJECT( Material, r_ReplicatedMaterial )
			ADD_VAR( ::IntProperty, m_nMaxWeaponLagPitch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMaxWeaponLagYaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxKickbackDistanceY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxKickbackDistanceX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fKickbackBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastKickbackTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCreditCost, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, m_TracerBeamTemplate )
			ADD_VAR( ::FloatProperty, m_fShowTracerDistance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nTracerInterval, 0xFFFFFFFF )
			ADD_OBJECT( TrAnimNodeBlendByDeviceAnim, m_DeviceAnimNode )
			ADD_VAR( ::FloatProperty, m_fLockTargetTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, c_LockedActor )
			ADD_VAR( ::FloatProperty, c_fLockTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, s_iCheatCountAmmo, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_ZoomOutSoundCue )
			ADD_OBJECT( SoundCue, m_ZoomInSoundCue )
			ADD_OBJECT( SoundCue, m_DryFireSoundCue )
			ADD_OBJECT( SoundCue, m_ReloadAmmoSoundCue )
			ADD_VAR( ::FloatProperty, m_fPctTimeBeforeReload, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fReloadTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_RemainingAmmoInClip, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMaxCarriedAmmo, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nLowAmmoWarning, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nAltReticuleIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fQuickRetrieveEquipTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyCorrectionRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAimingModeAccuracyBonus, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyLossMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyLossOnShot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyLossOnWeaponSwitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyLossOnJump, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDefaultAccuracy, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bTinyWeaponsEnabled, 0x4000000 )
			ADD_VAR( ::BoolProperty, r_bIsReloading, 0x2000000 )
			ADD_VAR( ::BoolProperty, m_bResumeZoomOnReloadEnd, 0x1000000 )
			ADD_VAR( ::BoolProperty, m_bEndZoomOnReload, 0x800000 )
			ADD_VAR( ::BoolProperty, m_bUseMeshZoomOffset, 0x400000 )
			ADD_VAR( ::BoolProperty, m_bCanZoom, 0x200000 )
			ADD_VAR( ::BoolProperty, m_bAllowHoldDownFire, 0x80000 )
			ADD_VAR( ::BoolProperty, m_bWantsToFire, 0x40000 )
			ADD_VAR( ::BoolProperty, m_bIsPassive, 0x20000 )
			ADD_VAR( ::BoolProperty, m_bIsKickbackAdditive, 0x10000 )
			ADD_VAR( ::BoolProperty, m_bSpawnTracerBeams, 0x8000 )
			ADD_VAR( ::BoolProperty, m_bSpawnTracers, 0x4000 )
			ADD_VAR( ::BoolProperty, m_bUsesDeployMode, 0x2000 )
			ADD_VAR( ::BoolProperty, c_bLocking, 0x1000 )
			ADD_VAR( ::BoolProperty, m_bForceReplicateAmmoOnFire, 0x800 )
			ADD_VAR( ::BoolProperty, r_bReadyToFire, 0x400 )
			ADD_VAR( ::BoolProperty, m_bCanEarlyAbortReload, 0x200 )
			ADD_VAR( ::BoolProperty, m_bReloadBulletInChamber, 0x100 )
			ADD_VAR( ::BoolProperty, m_bPendingReload, 0x80 )
			ADD_VAR( ::BoolProperty, m_bReloadSingles, 0x40 )
			ADD_VAR( ::BoolProperty, m_bAllowReloads, 0x20 )
			ADD_VAR( ::BoolProperty, m_bLowAmmoOn, 0x10 )
			ADD_VAR( ::BoolProperty, m_bRequireAimMode, 0x8 )
			ADD_VAR( ::BoolProperty, m_bHighlightEnemies, 0x4 )
			ADD_VAR( ::BoolProperty, m_bEquipEffectsApplied, 0x2 )
			ADD_VAR( ::BoolProperty, m_bAllowMultipleTargets, 0x1 )
			ADD_VAR( ::FloatProperty, m_fConeAttackAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDamageRadius, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_TracerType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_eEquipAt, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBWeaponTypeId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBWeaponBaseId, 0xFFFFFFFF )
			byte GetFireModeNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetFireModeNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool IsValidTarget( class Actor* Target, int nFireMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.IsValidTarget" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = Target;
				*( int* )( params + 4 ) = nFireMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsEnemy( class Actor* Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.IsEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsInsideCone( Vector SourceLookDir, class Actor* TargetActor, Vector StartCone, float MinCosine )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.IsInsideCone" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( Vector* )params = SourceLookDir;
				*( class Actor** )( params + 12 ) = TargetActor;
				*( Vector* )( params + 16 ) = StartCone;
				*( float* )( params + 28 ) = MinCosine;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldAddToImpactList( class Actor* HitActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ShouldAddToImpactList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )params = HitActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TickInHandWeapon( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.TickInHandWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetLock(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ResetLock" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* GetLockedTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetLockedTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			class TrDeployable* SpawnPet( bool bPet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.SpawnPet" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bPet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrDeployable** )( params + function->return_val_offset() );
			}

			float GetTargetAccuracy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetTargetAccuracy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void RestoreAccuracy( float fTimeStep )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.RestoreAccuracy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = fTimeStep;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RestoreKickback( float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.RestoreKickback" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsInLOS( class Actor* TouchedActor, Vector ExpectedLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.IsInLOS" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )params = TouchedActor;
				*( Vector* )( params + 4 ) = ExpectedLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AttachHandsMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AttachHandsMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrDeviceContentData* LoadMeshData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.LoadMeshData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrDeviceContentData** )( params + function->return_val_offset() );
			}

			int ValidateClientReportedHit( byte FiringMode, void* Impact, bool bHeadShot, bool bDeviceIsFiring )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ValidateClientReportedHit" );
				byte *params = ( byte* )( malloc( 89 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( bool* )( params + 84 ) = bHeadShot;
				*( bool* )( params + 88 ) = bDeviceIsFiring;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int ValidateClientReportedHitInternal( byte FiringMode, void* Impact, bool bHeadShot, bool bDeviceIsFiring )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ValidateClientReportedHitInternal" );
				byte *params = ( byte* )( malloc( 89 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( bool* )( params + 84 ) = bHeadShot;
				*( bool* )( params + 88 ) = bDeviceIsFiring;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetObjectReferencerName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetObjectReferencerName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetObjectReferencerPackageName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetObjectReferencerPackageName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int AddAmmo( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AddAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool ReplicateAmmoOnWeaponFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ReplicateAmmoOnWeaponFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ConsumeAmmo_Internal( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ConsumeAmmo_Internal" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConsumeAmmo( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ConsumeAmmo" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* GetTraceOwner(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetTraceOwner" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void AttachWeaponTo( ScriptName SocketName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AttachWeaponTo" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 4 ) = SocketName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateFirstPersonHandsMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CreateFirstPersonHandsMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeVisibility( bool bIsVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ChangeVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIsVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CentralUpdateHandsMesh( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CentralUpdateHandsMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateHandsMesh( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.UpdateHandsMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateOverlayMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CreateOverlayMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayWeaponEquip(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PlayWeaponEquip" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayRetrieveAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.OnPlayRetrieveAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayWeaponPutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PlayWeaponPutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponEmpty(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.WeaponEmpty" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSwitchToWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.OnSwitchToWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSwitchAwayFromWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.OnSwitchAwayFromWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWeaponSet( bool bOptionalSet, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ClientWeaponSet" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bOptionalSet;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFireEffects( byte FireModeNum, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PlayFireEffects" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = FireModeNum;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFireAnimation( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PlayFireAnimation" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShakeView(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ShakeView" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldFireTracer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ShouldFireTracer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldFireTracerBeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ShouldFireTracerBeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SpawnTracerBeam( Vector Start, Vector End )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.SpawnTracerBeam" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = Start;
				*( Vector* )( params + 12 ) = End;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrProj_Tracer* SpawnTracerEffect( Vector HitLocation, float HitDistance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.SpawnTracerEffect" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitLocation;
				*( float* )( params + 12 ) = HitDistance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrProj_Tracer** )( params + function->return_val_offset() );
			}

			class TrProj_Tracer* GetTracer( Vector SpawnLocation, Rotator SpawnRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetTracer" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = SpawnLocation;
				*( Rotator* )( params + 12 ) = SpawnRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrProj_Tracer** )( params + function->return_val_offset() );
			}

			int GetNumRoundsCurrentlyInClip(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetNumRoundsCurrentlyInClip" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool HasAmmo( byte FireModeNum, int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.HasAmmo" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = FireModeNum;
				*( int* )( params + 4 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasAnyAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.HasAnyAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowSwitchTo( class Weapon* NewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AllowSwitchTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )params = NewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float CalculateRangeDamageFalloff( float Dist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CalculateRangeDamageFalloff" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Dist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void InstantFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.InstantFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessInstantHit( byte FiringMode, void* Impact, int NumHits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ProcessInstantHit" );
				byte *params = ( byte* )( malloc( 85 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( int* )( params + 84 ) = NumHits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerNotifyHit( byte FiringMode, void* Impact, bool bHeadShot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ServerNotifyHit" );
				byte *params = ( byte* )( malloc( 85 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( bool* )( params + 84 ) = bHeadShot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessInstantHit_Internal( byte FiringMode, void* Impact, bool bHeadShot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ProcessInstantHit_Internal" );
				byte *params = ( byte* )( malloc( 85 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( bool* )( params + 84 ) = bHeadShot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float ModifyInstantHitDamage( byte FiringMode, void* Impact, float Damage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ModifyInstantHitDamage" );
				byte *params = ( byte* )( malloc( 85 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( float* )( params + 84 ) = Damage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void ProcessEffect( class Actor* Target, byte FiringMode, byte efType, bool bRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ProcessEffect" );
				byte *params = ( byte* )( malloc( 10 ) );
				*( class Actor** )params = Target;
				*( byte* )( params + 4 ) = FiringMode;
				*( byte* )( params + 5 ) = efType;
				*( bool* )( params + 8 ) = bRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UsesPower(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.UsesPower" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsDeviceCoolingDown( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.IsDeviceCoolingDown" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EnterDeployMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.EnterDeployMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ExitDeployMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ExitDeployMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleActivate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ToggleActivate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PayAccuracyForJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PayAccuracyForJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PayAccuracyForWeaponSwitch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PayAccuracyForWeaponSwitch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PayAccuracyForShot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PayAccuracyForShot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Rotator AddSpreadWithAccuracy( Rotator BaseAim, float fAccuracy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AddSpreadWithAccuracy" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )params = BaseAim;
				*( float* )( params + 12 ) = fAccuracy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator ApplyKickbackToAim( Rotator Aim )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ApplyKickbackToAim" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )params = Aim;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void* GetCurrentKickbackAmount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetCurrentKickbackAmount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool AddKickback(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AddKickback" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Rotator GetAdjustedAim( Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetAdjustedAim" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool ShowWeaponRedLowAmmoIndicator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ShowWeaponRedLowAmmoIndicator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedToVisitInventoryStation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.NeedToVisitInventoryStation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetAmmoCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetAmmoCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void UpdateLowAmmoWarning(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.UpdateLowAmmoWarning" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* GetProjectileClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetProjectileClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			Vector GetClientSideProjectileFireStartLoc( Vector AimDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetClientSideProjectileFireStartLoc" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = AimDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			class Projectile* ProjectileFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ProjectileFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Projectile** )( params + function->return_val_offset() );
			}

			void DestroyOldestProjectileOverLimit( class Projectile* newProjectile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.DestroyOldestProjectileOverLimit" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )params = newProjectile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireAmmunition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.FireAmmunition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float MaxRange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.MaxRange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetWeaponRange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetWeaponRange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Rotator GetAimForCamera( Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetAimForCamera" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool CanClientRequestReloadNow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CanClientRequestReloadNow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void HolderEnteredVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.HolderEnteredVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetReloadTime( class PlayerReplicationInfo* PRI, byte EquipPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetReloadTime" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				*( byte* )( params + 4 ) = EquipPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void ClearMeshAnimSeqNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ClearMeshAnimSeqNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CacheMeshAnimSeqNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CacheMeshAnimSeqNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SuppressAnimNotifies( bool bSuppress )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.SuppressAnimNotifies" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bSuppress;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsReloading(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.IsReloading" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RequestReload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.RequestReload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnClientReloaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.OnClientReloaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PerformInactiveReload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PerformInactiveReload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int CalcAmountToLoad(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CalcAmountToLoad" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ClientFinishedReload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ClientFinishedReload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResumeZoomOnReloadEnd(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ResumeZoomOnReloadEnd" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayReloadAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PlayReloadAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableWeaponReadyToFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.EnableWeaponReadyToFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReloadComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.OnReloadComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginAReload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.BeginAReload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int AddCarriedAmmo( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AddCarriedAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void UpdateReplicatedCarriedAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.UpdateReplicatedCarriedAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GoInactiveDueToOffhand(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GoInactiveDueToOffhand" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.StopFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.BeginFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetEquipTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetEquipTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void TimeWeaponPutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.TimeWeaponPutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetPutDownTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetPutDownTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool CanFireOffhandNow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CanFireOffhandNow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerOnClientDeniedFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ServerOnClientDeniedFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyEquipEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ApplyEquipEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveEquipEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.RemoveEquipEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPosition( class UDKPawn* Holder, float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.SetPosition" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UDKPawn** )params = Holder;
				*( float* )( params + 4 ) = DeltaSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int LagRot( int NewValue, int LastValue, float MaxDiff, int Index, float DeltaSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.LagRot" );
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

			bool ShouldRefire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ShouldRefire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Activate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.Activate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AnnounceInvalidPickup( class TrPawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AnnounceInvalidPickup" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DenyPickupQuery( ScriptClass* ItemClass, class Actor* Pickup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.DenyPickupQuery" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = ItemClass;
				*( class Actor** )( params + 4 ) = Pickup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PutDownFast(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PutDownFast" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceEndFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ForceEndFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanAutoDeviceFireNow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CanAutoDeviceFireNow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CustomFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CustomFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.AttachMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponPlaySoundLocal( class SoundCue* Sound, float NoiseLoudness )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.WeaponPlaySoundLocal" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SoundCue** )params = Sound;
				*( float* )( params + 4 ) = NoiseLoudness;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWeaponThrown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ClientWeaponThrown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateShotsFired( bool Reset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.UpdateShotsFired" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = Reset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartZoom( class UTPlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.StartZoom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndZoom( class UTPlayerController* PC, bool bReturningTo3P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.EndZoom" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerController** )params = PC;
				*( bool* )( params + 4 ) = bReturningTo3P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanViewZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CanViewZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetAltReticule(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.SetAltReticule" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetAltReticule(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ResetAltReticule" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* CalcWeaponFire( Vector StartTrace, Vector EndTrace, Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.CalcWeaponFire" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )params = StartTrace;
				*( Vector* )( params + 12 ) = EndTrace;
				*( Vector* )( params + 36 ) = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void PlayDryFireZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.PlayDryFireZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BuffMaxCarriedAmmo( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.BuffMaxCarriedAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetMaxAmmoCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetMaxAmmoCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int GetBasePickupAmmoAmount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.GetBasePickupAmmoAmount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ServerStartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.ServerStartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateWeaponMICs(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice.UpdateWeaponMICs" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
