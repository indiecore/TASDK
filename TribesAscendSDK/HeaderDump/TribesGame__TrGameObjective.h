#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGameObjective." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGameObjective." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGameObjective." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGameObjective : public UTGameObjective
	{
	public:
			ADD_OBJECT( ScriptClass, m_AssistAccolade )
			ADD_VAR( ::FloatProperty, fUpgradeAssistTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMarker2DDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DESTROY_ASSIST_PERCENTAGE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, REPAIR_ASSIST_PERCENTAGE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInstigatorNamePlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fObjectiveNamePlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fObjectiveHealthBarHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fObjectiveHealthBarWidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fObjectiveHealthBarPlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fObjectiveHealthBarPlacementX, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_HealthBarMIC )
			ADD_VAR( ::FloatProperty, m_fRepairBoost, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, m_UpgradeTemplate )
			ADD_VAR( ::IntProperty, r_nUpgradeLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPromptMessageSwitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPromptMessageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_bReset, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, DestroyedTemplate )
			ADD_VAR( ::FloatProperty, m_fLifeAfterDeathSecs, 0xFFFFFFFF )
			ADD_OBJECT( Controller, m_LastDamager )
			ADD_OBJECT( SoundCue, m_ExplosionSound )
			ADD_VAR( ::BoolProperty, m_bAlwaysRelevantToSameTeam, 0x8000 )
			ADD_VAR( ::BoolProperty, m_bHurtByFriendlyFire, 0x4000 )
			ADD_VAR( ::BoolProperty, m_bDestroyable, 0x2000 )
			ADD_VAR( ::BoolProperty, m_bShowObjectivesForcesMarker, 0x1000 )
			ADD_VAR( ::BoolProperty, m_bIsRepairable, 0x800 )
			ADD_VAR( ::BoolProperty, m_bIsUpgradeable, 0x400 )
			ADD_VAR( ::BoolProperty, m_bHasPromptText, 0x200 )
			ADD_VAR( ::BoolProperty, r_bInDestroyedState, 0x100 )
			ADD_VAR( ::BoolProperty, m_bIsRepairableAfterDeath, 0x80 )
			ADD_VAR( ::BoolProperty, m_bPostRenderForEnemy, 0x40 )
			ADD_VAR( ::BoolProperty, m_bVisibilityRequiredForEnemy, 0x20 )
			ADD_VAR( ::BoolProperty, m_bForceShowHUD, 0x10 )
			ADD_VAR( ::BoolProperty, m_bReceivesPowerFromGenerator, 0x8 )
			ADD_VAR( ::BoolProperty, r_bIsPowered, 0x4 )
			ADD_VAR( ::BoolProperty, m_bInstantOnlineSound, 0x2 )
			ADD_VAR( ::BoolProperty, m_bAutoPlayOnlineSound, 0x1 )
			ADD_OBJECT( PhysicsAsset, m_OfflinePhysicsAsset )
			ADD_OBJECT( PhysicsAsset, m_OnlinePhysicsAsset )
			ADD_OBJECT( ScriptClass, m_ExplosionLightClass )
			ADD_VAR( ::StrProperty, m_sScreenName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOuterExplosionShakeRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInnerExplosionShakeRadius, 0xFFFFFFFF )
			ADD_OBJECT( CameraAnim, m_ExplosionShake )
			ADD_OBJECT( ParticleSystem, m_ExplosionTemplate )
			ADD_VAR( ::FloatProperty, m_fShieldHitRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fShieldHitTargetTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fShieldHitTargetScale, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_ShieldMIC )
			ADD_VAR( ::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MarkerOffset, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, m_ShieldNormalMap )
			ADD_OBJECT( Material, m_ShieldMaterial )
			ADD_VAR( ::FloatProperty, m_fShieldHealthPercentage, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nRepairHealthThreshold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCriticalHealthThreshold, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_vReplicatedHitInfo, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nHealthRegenRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nLastHealth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_MaxHealth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_Health, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_ObjectiveMIC )
			ADD_STRUCT( ::VectorProperty, CallInPosition, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, CallInRotation, 0xFFFFFFFF )
			ADD_OBJECT( TrStatsInterface, Stats )
			bool IsEnemy( class Actor* Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.IsEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsInLOS_Basic( class Pawn* TouchedPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.IsInLOS_Basic" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = TouchedPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ApplyServerSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ApplyServerSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetScreenName( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GetScreenName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetSpectatorName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GetSpectatorName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			float GetHealthAmount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GetHealthAmount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			int GetUpgradeCost( class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GetUpgradeCost" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )( params + 0 ) = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool ShouldShowPromptText( class Pawn* aPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ShouldShowPromptText" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = aPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Shootable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.Shootable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RegenerateHealth(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.RegenerateHealth" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoRepairs( int HealAmount, class Controller* EventInstigator, class Actor* DamageCauser, ScriptClass* DamageType, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.DoRepairs" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( int* )( params + 0 ) = HealAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( class Actor** )( params + 8 ) = DamageCauser;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( void** )( params + 16 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRecievedHitInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ClientRecievedHitInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayUpgradeEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ClientPlayUpgradeEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDestroyedEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.PlayDestroyedEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnHealthChanged( bool wasDamage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.OnHealthChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = wasDamage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDamageHealthEffects( int DamageAmount, int HitBoneIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.PlayDamageHealthEffects" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = DamageAmount;
				*( int* )( params + 4 ) = HitBoneIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDamageShieldEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.PlayDamageShieldEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayExplosion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.PlayExplosion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPowered( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.SetPowered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPowerStatusChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.OnPowerStatusChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.HideMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldPostRenderForCaH(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ShouldPostRenderForCaH" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Texture2D* GetMarker(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GetMarker" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Texture2D** )( params + function->return_val_offset() );
			}

			bool GetPossessiveInstigatorName( ScriptArray< wchar_t > &PlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GetPossessiveInstigatorName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlayerName = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BlocksLineChecksFromSourceActor( class Actor* SourceActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.BlocksLineChecksFromSourceActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = SourceActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnHelpTextCollisionProxy( byte HelpTextType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.SpawnHelpTextCollisionProxy" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = HelpTextType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldShowHelpText( byte HelpTextType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ShouldShowHelpText" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = HelpTextType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReceivesPowerFromGenerator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ReceivesPowerFromGenerator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PerformUpgrade( class TrPlayerController* Purchaser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.PerformUpgrade" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )( params + 0 ) = Purchaser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddUpgrader( class TrPlayerController* Upgrader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.AddUpgrader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )( params + 0 ) = Upgrader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDamageAssistance( class TrPlayerController* TrPC, int DamageAmount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.AddDamageAssistance" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerController** )( params + 0 ) = TrPC;
				*( int* )( params + 4 ) = DamageAmount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckRepairAssists(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.CheckRepairAssists" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckDestroyAssists(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.CheckDestroyAssists" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearDamageAssistance( bool bOnlyDamagers )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.ClearDamageAssistance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bOnlyDamagers;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GiveDestroyAccolade( class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GiveDestroyAccolade" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )( params + 0 ) = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetSpectatorHealthInfo( int &Health, int &MaxHealth )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GetSpectatorHealthInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = Health;
				*( int* )( params + 4 ) = MaxHealth;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Health = *( int* )( params + 0 );
				MaxHealth = *( int* )( params + 4 );
			}

			ScriptArray< wchar_t > GetSpectatorDescription(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.GetSpectatorDescription" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool IsAliveAndWell(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.IsAliveAndWell" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void InstantlyRegenerateHealth(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.InstantlyRegenerateHealth" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HideBasePlatform(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.HideBasePlatform" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RequiresLOSForRepairDeployable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.RequiresLOSForRepairDeployable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AwardKillAssists(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.AwardKillAssists" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AwardUpgradeAssists(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.AwardUpgradeAssists" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpgradePerformed( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGameObjective.OnUpgradePerformed" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
