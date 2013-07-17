#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTPawn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTPawn : public UDKPawn
	{
	public:
			bool CanDoubleJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.CanDoubleJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, CurrentCameraScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, WalkBob, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VestArmor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShieldBeltArmor, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, HoverboardClass )
			ADD_VAR( ::BoolProperty, bIsInvulnerable, 0x40 )
			ADD_VAR( ::BoolProperty, bFixedView, 0x1 )
			ADD_STRUCT( ::VectorProperty, FixedViewLoc, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, FixedViewRot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LandBob, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bJustLanded, 0x400 )
			ADD_VAR( ::BoolProperty, bLandRecovery, 0x800 )
			ADD_VAR( ::BoolProperty, bArmsAttached, 0x20000 )
			ADD_OBJECT( ScriptClass, CurrentWeaponAttachmentClass )
			Vector WeaponBob( float BobDamping, float JumpDamping )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.WeaponBob" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = BobDamping;
				*( float* )( params + 4 ) = JumpDamping;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float GetEyeHeight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetEyeHeight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool IsFirstPerson(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.IsFirstPerson" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AdjustPPEffects( class UTPlayerController* PC, bool bRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.AdjustPPEffects" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				*( bool* )( params + 4 ) = bRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float AdjustedStrength(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.AdjustedStrength" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			class UTPlayerReplicationInfo* GetUTPlayerReplicationInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetUTPlayerReplicationInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTPlayerReplicationInfo** )( params + function->return_val_offset() );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bStopDeathCamera, 0x2000 )
			void HeadVolumeChange( class PhysicsVolume* newHeadVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.HeadVolumeChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicsVolume** )( params + 0 ) = newHeadVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PoweredUp(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PoweredUp" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool InCombat(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.InCombat" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, LastPainSound, 0xFFFFFFFF )
			void RenderMapIcon( class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, void* FinalColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.RenderMapIcon" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class UTMapInfo** )( params + 0 ) = MP;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( class UTPlayerController** )( params + 8 ) = PlayerOwner;
				*( void** )( params + 12 ) = FinalColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, MapSize, 0xFFFFFFFF )
			void SetWalking( bool bNewIsWalking )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetWalking" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewIsWalking;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearBodyMatColor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ClearBodyMatColor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBodyMatColor( void* NewBodyMatColor, float NewOverlayDuration )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetBodyMatColor" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = NewBodyMatColor;
				*( float* )( params + 16 ) = NewOverlayDuration;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInvisible( bool bNowInvisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetInvisible" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNowInvisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkin( class Material* NewMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetSkin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Material** )( params + 0 ) = NewMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( UTWeaponAttachment, CurrentWeaponAttachment )
			void SetArmsSkin( class MaterialInterface* NewMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetArmsSkin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MaterialInterface** )( params + 0 ) = NewMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, CurrCharClassInfo )
			bool VerifyBodyMaterialInstance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.VerifyBodyMaterialInstance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetCharacterClassFromInfo( ScriptClass* Info, bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetCharacterClassFromInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = Info;
				*( bool* )( params + 4 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, SoundGroupClass )
			ADD_VAR( ::FloatProperty, DefaultMeshScale, 0xFFFFFFFF )
			void SetCharacterMeshInfo( class SkeletalMesh* SkelMesh, class MaterialInterface* HeadMaterial, class MaterialInterface* BodyMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetCharacterMeshInfo" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SkeletalMesh** )( params + 0 ) = SkelMesh;
				*( class MaterialInterface** )( params + 4 ) = HeadMaterial;
				*( class MaterialInterface** )( params + 8 ) = BodyMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPawnRBChannels( bool bRagdollMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetPawnRBChannels" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bRagdollMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetCharPhysState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ResetCharPhysState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTeamChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.NotifyTeamChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bReceivedValidTeam, 0x200000 )
			void SetFirstPersonArmsInfo( class SkeletalMesh* FirstPersonArmMesh, class MaterialInterface* ArmMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetFirstPersonArmsInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SkeletalMesh** )( params + 0 ) = FirstPersonArmMesh;
				*( class MaterialInterface** )( params + 4 ) = ArmMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTeamColor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetTeamColor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateShadowSettings( bool bWantShadow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.UpdateShadowSettings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWantShadow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReattachMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ReattachMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( AnimNodeBlend, FeignDeathBlend )
			ADD_OBJECT( AnimNodeSlot, FullBodyAnimSlot )
			ADD_OBJECT( AnimNodeSlot, TopHalfAnimSlot )
			ADD_OBJECT( UTAnimBlendByDriving, DrivingNode )
			ADD_OBJECT( UTAnimBlendByVehicle, VehicleNode )
			ADD_OBJECT( UTAnimBlendByHoverboarding, HoverboardingNode )
			void SetHandIKEnabled( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetHandIKEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAnimRateScale( float RateScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetAnimRateScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = RateScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetWeapAnimType( byte AnimType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetWeapAnimType" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = AnimType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LeaveABloodSplatterDecal( Vector HitLoc, Vector HitNorm )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.LeaveABloodSplatterDecal" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = HitLoc;
				*( Vector* )( params + 12 ) = HitNorm;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PerformEmoteCommand( void* EInfo, int PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PerformEmoteCommand" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )( params + 0 ) = EInfo;
				*( int* )( params + 52 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoPlayEmote( ScriptName InEmoteTag, int InPlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.DoPlayEmote" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = InEmoteTag;
				*( int* )( params + 8 ) = InPlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerPlayEmote( ScriptName InEmoteTag, int InPlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ServerPlayEmote" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = InEmoteTag;
				*( int* )( params + 8 ) = InPlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayEmote( ScriptName InEmoteTag, int InPlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayEmote" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = InEmoteTag;
				*( int* )( params + 8 ) = InPlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayAnim( class UTSeqAct_PlayAnim* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.OnPlayAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_PlayAnim** )( params + 0 ) = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnDefaultController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SpawnDefaultController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bWeaponBob, 0x200 )
			ADD_VAR( ::FloatProperty, JumpBob, 0xFFFFFFFF )
			void TurnOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.TurnOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool EncroachingOn( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.EncroachingOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EncroachedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.EncroachedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void gibbedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.gibbedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void JumpOffPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.JumpOffPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StuckOnPawn( class Pawn* OtherPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StuckOnPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = OtherPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Falling(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.Falling" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddVelocity( Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.AddVelocity" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.Died" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool StopFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StopFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BotFire( bool bFinished )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.BotFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bFinished;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool StopWeaponFiring(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StopWeaponFiring" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte ChooseFireMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ChooseFireMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool RecommendLongRangedAttack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.RecommendLongRangedAttack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float RangedAttackTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.RangedAttackTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PlayVictoryAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayVictoryAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::NameProperty, TauntNames, 0xFFFFFFFF )
			void OnModifyHealth( class SeqAct_ModifyHealth* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.OnModifyHealth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ModifyHealth** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetScreenName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetScreenName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void FaceRotation( Rotator NewRotation, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.FaceRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = NewRotation;
				*( float* )( params + 12 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateEyeHeight( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.UpdateEyeHeight" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, bobtime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Bob, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AppliedBob, 0xFFFFFFFF )
			Vector GetPawnViewLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetPawnViewLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void BecomeViewTarget( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.BecomeViewTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndViewTarget( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.EndViewTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetWeaponVisibility( bool bWeaponVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetWeaponVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWeaponVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetWeaponAttachmentVisibility( bool bAttachmentVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetWeaponAttachmentVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bAttachmentVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bWeaponAttachmentVisible, 0x40000 )
			void SetMeshVisibility( bool bVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetMeshVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DeactivateSpawnProtection(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.DeactivateSpawnProtection" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bSpawnDone, 0x2 )
			ADD_VAR( ::BoolProperty, bSpawnIn, 0x4 )
			void PlayTeleportEffect( bool bOut, bool bSound )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayTeleportEffect" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bOut;
				*( bool* )( params + 4 ) = bSound;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( SoundCue, SpawnSound )
			ADD_OBJECT( SoundCue, TeleportSound )
			ADD_OBJECT( CameraAnim, TransCameraAnim )
			void SpawnTransEffect( int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SpawnTransEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, TransInEffects )
			void StartDriving( class Vehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StartDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopDriving( class Vehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StopDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( UTClientSideWeaponPawn, ClientSideWeaponPawn )
			void ClientRestart(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ClientRestart" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetShieldStrength(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetShieldStrength" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, ThighpadArmor, 0xFFFFFFFF )
			int AbsorbDamage( int &Damage, int CurrentShieldStrength, float AbsorptionRate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.AbsorbDamage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = Damage;
				*( int* )( params + 4 ) = CurrentShieldStrength;
				*( float* )( params + 8 ) = AbsorptionRate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Damage = *( int* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			int ShieldAbsorb( int Damage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ShieldAbsorb" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Damage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bShieldAbsorb, 0x8 )
			ADD_OBJECT( SoundCue, ArmorHitSound )
			void AdjustDamage( int &InDamage, Vector &Momentum, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.AdjustDamage" );
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

			void DropFlag( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.DropFlag" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bJustDroppedOrb, 0x80 )
			void EnableInventoryPickup(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.EnableInventoryPickup" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HoldGameObject( class UDKCarriedObject* GameObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.HoldGameObject" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKCarriedObject** )( params + 0 ) = GameObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GiveHealth( int HealAmount, int HealMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GiveHealth" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = HealAmount;
				*( int* )( params + 4 ) = HealMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetDebugName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetDebugName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void PlayFootStepSound( int FootDown )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayFootStepSound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = FootDown;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, MaxFootstepDistSq, 0xFFFFFFFF )
			void ActuallyPlayFootstepSound( int FootDown )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ActuallyPlayFootstepSound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = FootDown;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptName GetMaterialBelowFeet(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetMaterialBelowFeet" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void PlayLandingSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayLandingSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, MaxJumpSoundDistSq, 0xFFFFFFFF )
			void PlayJumpingSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayJumpingSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldGib( ScriptClass* UTDamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ShouldGib" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = UTDamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SpawnHeadGib( ScriptClass* UTDamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SpawnHeadGib" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = UTDamageType;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bHeadGibbed, 0x10000 )
			class UTGib* SpawnGib( ScriptClass* GibClass, ScriptName BoneName, ScriptClass* UTDamageType, Vector HitLocation, bool bSpinGib )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SpawnGib" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptClass** )( params + 0 ) = GibClass;
				*( ScriptName* )( params + 4 ) = BoneName;
				*( ScriptClass** )( params + 12 ) = UTDamageType;
				*( Vector* )( params + 16 ) = HitLocation;
				*( bool* )( params + 28 ) = bSpinGib;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTGib** )( params + function->return_val_offset() );
			}

			void SpawnGibs( ScriptClass* UTDamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SpawnGibs" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = UTDamageType;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bGibbed, 0x8000 )
			ADD_VAR( ::FloatProperty, DeathTime, 0xFFFFFFFF )
			void TurnOffPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.TurnOffPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDying( ScriptClass* DamageType, Vector HitLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayDying" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = DamageType;
				*( Vector* )( params + 4 ) = HitLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bForcedFeignDeath, 0x100 )
			ADD_VAR( ::BoolProperty, bHideOnListenServer, 0x80000 )
			ADD_VAR( ::FloatProperty, DeathHipLinSpring, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeathHipLinDamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeathHipAngSpring, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeathHipAngDamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StartDeathAnimTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeLastTookDeathAnimDamage, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, DeathAnimDamageType )
			void DoingDeathAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.DoingDeathAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDefaultInventory(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.AddDefaultInventory" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CalcCamera( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.CalcCamera" );
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

			void SetThirdPersonCamera( bool bNewBehindView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetThirdPersonCamera" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewBehindView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, CameraZOffset, 0xFFFFFFFF )
			void FindGoodEndView( class PlayerController* InPC, Rotator &GoodRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.FindGoodEndView" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )( params + 0 ) = InPC;
				*( Rotator* )( params + 4 ) = GoodRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				GoodRotation = *( Rotator* )( params + 4 );
			}

			ADD_VAR( ::BoolProperty, bWinnerCam, 0x4000 )
			ADD_VAR( ::IntProperty, HeroCameraPitch, 0xFFFFFFFF )
			bool TryNewCamRot( class UTPlayerController* PC, Rotator ViewRotation, float &CamDist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.TryNewCamRot" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				*( Rotator* )( params + 4 ) = ViewRotation;
				*( float* )( params + 16 ) = CamDist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CamDist = *( float* )( params + 16 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetHeroCam( Rotator &out_CamRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetHeroCam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = out_CamRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamRot = *( Rotator* )( params + 0 );
			}

			ADD_VAR( ::FloatProperty, HeroCameraScale, 0xFFFFFFFF )
			bool CalcThirdPersonCam( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.CalcThirdPersonCam" );
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

			ADD_STRUCT( ::VectorProperty, CamOffset, 0xFFFFFFFF )
			Vector GetWeaponStartTraceLocation( class Weapon* CurrentWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetWeaponStartTraceLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = CurrentWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			bool Dodge( byte DoubleClickMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.Dodge" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = DoubleClickMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector BotDodge( Vector Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.BotDodge" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, DodgeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DodgeSpeedZ, 0xFFFFFFFF )
			bool PerformDodge( byte DoubleClickMove, Vector Dir, Vector Cross )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PerformDodge" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )( params + 0 ) = DoubleClickMove;
				*( Vector* )( params + 4 ) = Dir;
				*( Vector* )( params + 16 ) = Cross;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bDodging, 0x10 )
			ADD_VAR( ::IntProperty, JumpBootCharge, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentDir, 0xFFFFFFFF )
			void DoDoubleJump( bool bUpdating )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.DoDoubleJump" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bUpdating;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, DoubleJumpEyeHeight, 0xFFFFFFFF )
			void Gasp(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.Gasp" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFlying(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StartFlying" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopFlying(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StopFlying" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DoJump( bool bUpdating )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.DoJump" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bUpdating;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, DoubleJumpThreshold, 0xFFFFFFFF )
			void Landed( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.Landed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bStopOnDoubleLanding, 0x20 )
			ADD_VAR( ::FloatProperty, DefaultAirControl, 0xFFFFFFFF )
			void JumpOutOfWater( Vector JumpDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.JumpOutOfWater" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = JumpDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanMultiJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.CanMultiJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayDyingSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayDyingSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void SetPawnAmbientSound( class SoundCue* NewAmbientSound )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetPawnAmbientSound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SoundCue** )( params + 0 ) = NewAmbientSound;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SoundCue* GetPawnAmbientSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetPawnAmbientSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundCue** )( params + function->return_val_offset() );
			}

			void SetWeaponAmbientSound( class SoundCue* NewAmbientSound )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetWeaponAmbientSound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SoundCue** )( params + 0 ) = NewAmbientSound;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SoundCue* GetWeaponAmbientSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetWeaponAmbientSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundCue** )( params + function->return_val_offset() );
			}

			void SetOverlayMaterial( class MaterialInterface* NewOverlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetOverlayMaterial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MaterialInterface** )( params + 0 ) = NewOverlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class MaterialInterface* GetShieldMaterialInstance( bool bTeamGame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetShieldMaterialInstance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bTeamGame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MaterialInterface** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( MaterialInterface, ShieldBeltTeamMaterialInstances )
			ADD_OBJECT( MaterialInterface, ShieldBeltMaterialInstance )
			class MaterialInterface* GetOverlayMaterial(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetOverlayMaterial" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MaterialInterface** )( params + function->return_val_offset() );
			}

			void SetWeaponOverlayFlag( byte FlagToSet )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetWeaponOverlayFlag" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FlagToSet;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearWeaponOverlayFlag( byte FlagToClear )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ClearWeaponOverlayFlag" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FlagToClear;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyWeaponOverlayFlags( byte NewFlags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ApplyWeaponOverlayFlags" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = NewFlags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFeignDeathRecoveryAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StartFeignDeathRecoveryAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FeignDeathDelayTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.FeignDeathDelayTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, FeignDeathStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FeignDeathBodyAtRestSpeed, 0xFFFFFFFF )
			void PlayFeignDeath(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayFeignDeath" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, UnfeignFailedCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FeignDeathRecoveryStartTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, HeadBone, 0xFFFFFFFF )
			bool SetFeignEndLocation( Vector HitLocation, Vector FeignLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetFeignEndLocation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( Vector* )( params + 12 ) = FeignLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckValidLocation( Vector FeignLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.CheckValidLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = FeignLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerFeignDeath(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ServerFeignDeath" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FeignDeath(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.FeignDeath" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceRagdoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ForceRagdoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FiringModeUpdated( class Weapon* InWeapon, byte InFiringMode, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.FiringModeUpdated" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( byte* )( params + 4 ) = InFiringMode;
				*( bool* )( params + 8 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBigHead(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetBigHead" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bKillsAffectHead, 0x400000 )
			void FireRateChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.FireRateChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, m_ClientSideWeaponPawnClass )
			void SetHeadScale( float NewScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetHeadScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = NewScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPuttingDownWeapon( bool bNowPuttingDownWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetPuttingDownWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNowPuttingDownWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetPuttingDownWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetPuttingDownWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TakeDamage( int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = Damage;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( UTProjectile, AttachedProj )
			ADD_VAR( ::FloatProperty, AccumulationTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AccumulateDamage, 0xFFFFFFFF )
			void WeaponFired( class Weapon* InWeapon, bool bViaReplication, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.WeaponFired" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponStoppedFiring( class Weapon* InWeapon, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.WeaponStoppedFiring" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponChanged( class UTWeapon* NewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.WeaponChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTWeapon** )( params + 0 ) = NewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponAttachmentChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.WeaponAttachmentChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayHit( float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayHit" );
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

			void PlayTakeHitEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PlayTakeHitEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeHitBlendedOut(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.TakeHitBlendedOut" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerHoverboard(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ServerHoverboard" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bHasHoverboard, 0x1000 )
			ADD_VAR( ::FloatProperty, LastHoverboardTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinHoverboardInterval, 0xFFFFFFFF )
			void OnUseHoverboard( class UTSeqAct_UseHoverboard* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.OnUseHoverboard" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_UseHoverboard** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchWeapon( byte NewGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SwitchWeapon" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = NewGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDrowningDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.TakeDrowningDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsLocationOnHead( void* &Impact, float AdditionalScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.IsLocationOnHead" );
				byte *params = ( byte* )( malloc( 84 ) );
				*( void** )( params + 0 ) = Impact;
				*( float* )( params + 80 ) = AdditionalScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Impact = *( void** )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, HeadHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeadRadius, 0xFFFFFFFF )
			void ModifyRotForDebugFreeCam( Rotator &out_CamRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.ModifyRotForDebugFreeCam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = out_CamRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamRot = *( Rotator* )( params + 0 );
			}

			void AdjustCameraScale( bool bMoveCameraIn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.AdjustCameraScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bMoveCameraIn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, CameraScaleMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraScaleMax, 0xFFFFFFFF )
			Rotator GetViewRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetViewRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void TornOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.TornOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOverlayVisibility( bool bVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.SetOverlayVisibility" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeFallingDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.TakeFallingDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ForceFeedbackWaveform, FallingDamageWaveForm )
			void RigidBodyCollision( void* &RigidCollisionData, int ContactIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.RigidBodyCollision" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 8 ) = RigidCollisionData;
				*( int* )( params + 44 ) = ContactIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				RigidCollisionData = *( void** )( params + 8 );
			}

			void OnRanOver( class SVehicle* Vehicle, int WheelIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.OnRanOver" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SVehicle** )( params + 0 ) = Vehicle;
				*( int* )( params + 8 ) = WheelIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StuckFalling(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.StuckFalling" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnExitVehicle( class UTSeqAct_ExitVehicle* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.OnExitVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_ExitVehicle** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnInfiniteAmmo( class UTSeqAct_InfiniteAmmo* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.OnInfiniteAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_InfiniteAmmo** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PossessedBy( class Controller* C, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PossessedBy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = C;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NeedToTurn( Vector targ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.NeedToTurn" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = targ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_STRUCT( ::VectorProperty, OldCameraPosition, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bKilledByBio, 0x800000 )
			ADD_VAR( ::FloatProperty, BioBurnAwayTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BioEffectName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RagdollLifespan, 0xFFFFFFFF )
			ScriptClass* GetFamilyInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.GetFamilyInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void PostTeleport( class Teleporter* OutTeleporter )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PostTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Teleporter** )( params + 0 ) = OutTeleporter;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBigTeleport(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTPawn.PostBigTeleport" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bPostRenderTraceSucceeded, 0x100000 )
			ADD_VAR( ::IntProperty, SuperHealthMax, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, WeaponSocket, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, WeaponSocket2, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PawnEffectSockets, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeadOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TeamBeaconPlayerInfoMaxDist, 0xFFFFFFFF )
			ADD_OBJECT( Texture, SpeakingBeaconTexture )
			ADD_VAR( ::FloatProperty, DesiredMeshScale, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
