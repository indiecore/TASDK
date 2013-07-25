#pragma once
#include "Engine__SoundCue.h"
#include "UTGame__UTWeaponAttachment.h"
#include "UTGame__UTSeqAct_ExitVehicle.h"
#include "UDKBase__UDKPawn.h"
#include "Engine__Material.h"
#include "Engine__AnimNodeSlot.h"
#include "Engine__AnimNodeBlend.h"
#include "Engine__Weapon.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__CameraAnim.h"
#include "UTGame__UTAnimBlendByDriving.h"
#include "UTGame__UTAnimBlendByVehicle.h"
#include "UTGame__UTWeapon.h"
#include "UTGame__UTAnimBlendByHoverboarding.h"
#include "UTGame__UTClientSideWeaponPawn.h"
#include "UTGame__UTSeqAct_UseHoverboard.h"
#include "Engine__MaterialInterface.h"
#include "UTGame__UTProjectile.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "Engine__Canvas.h"
#include "Engine__Texture.h"
#include "UTGame__UTPlayerController.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "Engine__PhysicsVolume.h"
#include "UTGame__UTMapInfo.h"
#include "UTGame__UTSeqAct_PlayAnim.h"
#include "Engine__Actor.h"
#include "Engine__Teleporter.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "Engine__PlayerController.h"
#include "Engine__SeqAct_ModifyHealth.h"
#include "Engine__Vehicle.h"
#include "UDKBase__UDKCarriedObject.h"
#include "UTGame__UTGib.h"
#include "Engine__HUD.h"
#include "Engine__SVehicle.h"
#include "UTGame__UTSeqAct_InfiniteAmmo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPawn : public UDKPawn
	{
	public:
		ADD_VAR(::FloatProperty, CurrentCameraScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, WalkBob, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, VestArmor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ShieldBeltArmor, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, HoverboardClass)
		ADD_VAR(::BoolProperty, bIsInvulnerable, 0x40)
		ADD_VAR(::BoolProperty, bFixedView, 0x1)
		ADD_STRUCT(::VectorProperty, FixedViewLoc, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, FixedViewRot, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, LandBob, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bJustLanded, 0x400)
		ADD_VAR(::BoolProperty, bLandRecovery, 0x800)
		ADD_VAR(::BoolProperty, bArmsAttached, 0x20000)
		ADD_OBJECT(ScriptClass, CurrentWeaponAttachmentClass)
		ADD_VAR(::BoolProperty, bStopDeathCamera, 0x2000)
		ADD_VAR(::FloatProperty, LastPainSound, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MapSize, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_OBJECT(UTWeaponAttachment, CurrentWeaponAttachment)
		ADD_OBJECT(ScriptClass, CurrCharClassInfo)
		ADD_OBJECT(ScriptClass, SoundGroupClass)
		ADD_VAR(::FloatProperty, DefaultMeshScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bReceivedValidTeam, 0x200000)
		ADD_OBJECT(AnimNodeBlend, FeignDeathBlend)
		ADD_OBJECT(AnimNodeSlot, FullBodyAnimSlot)
		ADD_OBJECT(AnimNodeSlot, TopHalfAnimSlot)
		ADD_OBJECT(UTAnimBlendByDriving, DrivingNode)
		ADD_OBJECT(UTAnimBlendByVehicle, VehicleNode)
		ADD_OBJECT(UTAnimBlendByHoverboarding, HoverboardingNode)
		ADD_VAR(::BoolProperty, bWeaponBob, 0x200)
		ADD_VAR(::FloatProperty, JumpBob, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TauntNames, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, bobtime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Bob, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AppliedBob, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWeaponAttachmentVisible, 0x40000)
		ADD_VAR(::BoolProperty, bSpawnDone, 0x2)
		ADD_VAR(::BoolProperty, bSpawnIn, 0x4)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'SpawnProtectionColor'!
		ADD_OBJECT(SoundCue, SpawnSound)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'TranslocateColor'!
		ADD_OBJECT(SoundCue, TeleportSound)
		ADD_OBJECT(CameraAnim, TransCameraAnim)
		ADD_OBJECT(ScriptClass, TransInEffects)
		ADD_OBJECT(UTClientSideWeaponPawn, ClientSideWeaponPawn)
		ADD_VAR(::FloatProperty, ThighpadArmor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShieldAbsorb, 0x8)
		ADD_OBJECT(SoundCue, ArmorHitSound)
		ADD_VAR(::BoolProperty, bJustDroppedOrb, 0x80)
		ADD_VAR(::FloatProperty, MaxFootstepDistSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxJumpSoundDistSq, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHeadGibbed, 0x10000)
		ADD_VAR(::BoolProperty, bGibbed, 0x8000)
		ADD_VAR(::FloatProperty, DeathTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForcedFeignDeath, 0x100)
		ADD_VAR(::BoolProperty, bHideOnListenServer, 0x80000)
		ADD_VAR(::FloatProperty, DeathHipLinSpring, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeathHipLinDamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeathHipAngSpring, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeathHipAngDamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartDeathAnimTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeLastTookDeathAnimDamage, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DeathAnimDamageType)
		ADD_VAR(::FloatProperty, CameraZOffset, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWinnerCam, 0x4000)
		ADD_VAR(::IntProperty, HeroCameraPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeroCameraScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CamOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, DodgeSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DodgeSpeedZ, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDodging, 0x10)
		ADD_VAR(::IntProperty, JumpBootCharge, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentDir, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleJumpEyeHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleJumpThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bStopOnDoubleLanding, 0x20)
		ADD_VAR(::FloatProperty, DefaultAirControl, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, ShieldBeltTeamMaterialInstances)
		ADD_OBJECT(MaterialInterface, ShieldBeltMaterialInstance)
		ADD_VAR(::FloatProperty, FeignDeathStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FeignDeathBodyAtRestSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, UnfeignFailedCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FeignDeathRecoveryStartTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, HeadBone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bKillsAffectHead, 0x400000)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.DrivenWeaponPawnInfo' for the property named 'LastDrivenWeaponPawn'!
		ADD_OBJECT(ScriptClass, m_ClientSideWeaponPawnClass)
		ADD_OBJECT(UTProjectile, AttachedProj)
		ADD_VAR(::FloatProperty, AccumulationTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccumulateDamage, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasHoverboard, 0x1000)
		ADD_VAR(::FloatProperty, LastHoverboardTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinHoverboardInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraScaleMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraScaleMax, 0xFFFFFFFF)
		ADD_OBJECT(ForceFeedbackWaveform, FallingDamageWaveForm)
		ADD_STRUCT(::VectorProperty, OldCameraPosition, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bKilledByBio, 0x800000)
		ADD_VAR(::FloatProperty, BioBurnAwayTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BioEffectName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RagdollLifespan, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPostRenderTraceSucceeded, 0x100000)
		ADD_VAR(::IntProperty, SuperHealthMax, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WeaponSocket, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WeaponSocket2, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PawnEffectSockets, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamBeaconPlayerInfoMaxDist, 0xFFFFFFFF)
		ADD_OBJECT(Texture, SpeakingBeaconTexture)
		ADD_VAR(::FloatProperty, DesiredMeshScale, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'CanDoubleJump'
		// Here lies the not-yet-implemented method 'WeaponBob'
		// Here lies the not-yet-implemented method 'GetEyeHeight'
		// Here lies the not-yet-implemented method 'IsFirstPerson'
		// Here lies the not-yet-implemented method 'AdjustPPEffects'
		// Here lies the not-yet-implemented method 'AdjustedStrength'
		// Here lies the not-yet-implemented method 'GetUTPlayerReplicationInfo'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'HeadVolumeChange'
		// Here lies the not-yet-implemented method 'PoweredUp'
		// Here lies the not-yet-implemented method 'InCombat'
		// Here lies the not-yet-implemented method 'RenderMapIcon'
		// Here lies the not-yet-implemented method 'SetWalking'
		// Here lies the not-yet-implemented method 'ClearBodyMatColor'
		// Here lies the not-yet-implemented method 'SetBodyMatColor'
		// Here lies the not-yet-implemented method 'SetInvisible'
		// Here lies the not-yet-implemented method 'SetSkin'
		// Here lies the not-yet-implemented method 'SetArmsSkin'
		// Here lies the not-yet-implemented method 'VerifyBodyMaterialInstance'
		// Here lies the not-yet-implemented method 'SetCharacterClassFromInfo'
		// Here lies the not-yet-implemented method 'SetCharacterMeshInfo'
		// Here lies the not-yet-implemented method 'SetPawnRBChannels'
		// Here lies the not-yet-implemented method 'ResetCharPhysState'
		// Here lies the not-yet-implemented method 'NotifyTeamChanged'
		// Here lies the not-yet-implemented method 'SetFirstPersonArmsInfo'
		// Here lies the not-yet-implemented method 'SetTeamColor'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'UpdateShadowSettings'
		// Here lies the not-yet-implemented method 'ReattachMesh'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'SetHandIKEnabled'
		// Here lies the not-yet-implemented method 'SetAnimRateScale'
		// Here lies the not-yet-implemented method 'SetWeapAnimType'
		// Here lies the not-yet-implemented method 'LeaveABloodSplatterDecal'
		// Here lies the not-yet-implemented method 'PerformEmoteCommand'
		// Here lies the not-yet-implemented method 'DoPlayEmote'
		// Here lies the not-yet-implemented method 'ServerPlayEmote'
		// Here lies the not-yet-implemented method 'PlayEmote'
		// Here lies the not-yet-implemented method 'OnPlayAnim'
		// Here lies the not-yet-implemented method 'SpawnDefaultController'
		// Here lies the not-yet-implemented method 'TurnOff'
		// Here lies the not-yet-implemented method 'EncroachingOn'
		// Here lies the not-yet-implemented method 'EncroachedBy'
		// Here lies the not-yet-implemented method 'gibbedBy'
		// Here lies the not-yet-implemented method 'JumpOffPawn'
		// Here lies the not-yet-implemented method 'StuckOnPawn'
		// Here lies the not-yet-implemented method 'Falling'
		// Here lies the not-yet-implemented method 'AddVelocity'
		// Here lies the not-yet-implemented method 'Died'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'StopFiring'
		// Here lies the not-yet-implemented method 'BotFire'
		// Here lies the not-yet-implemented method 'StopWeaponFiring'
		// Here lies the not-yet-implemented method 'ChooseFireMode'
		// Here lies the not-yet-implemented method 'RecommendLongRangedAttack'
		// Here lies the not-yet-implemented method 'RangedAttackTime'
		// Here lies the not-yet-implemented method 'PlayVictoryAnimation'
		// Here lies the not-yet-implemented method 'OnModifyHealth'
		// Here lies the not-yet-implemented method 'GetScreenName'
		// Here lies the not-yet-implemented method 'FaceRotation'
		// Here lies the not-yet-implemented method 'UpdateEyeHeight'
		// Here lies the not-yet-implemented method 'GetPawnViewLocation'
		// Here lies the not-yet-implemented method 'BecomeViewTarget'
		// Here lies the not-yet-implemented method 'EndViewTarget'
		// Here lies the not-yet-implemented method 'SetWeaponVisibility'
		// Here lies the not-yet-implemented method 'SetWeaponAttachmentVisibility'
		// Here lies the not-yet-implemented method 'SetMeshVisibility'
		// Here lies the not-yet-implemented method 'DeactivateSpawnProtection'
		// Here lies the not-yet-implemented method 'PlayTeleportEffect'
		// Here lies the not-yet-implemented method 'SpawnTransEffect'
		// Here lies the not-yet-implemented method 'StartDriving'
		// Here lies the not-yet-implemented method 'StopDriving'
		// Here lies the not-yet-implemented method 'ClientRestart'
		// Here lies the not-yet-implemented method 'GetShieldStrength'
		// Here lies the not-yet-implemented method 'AbsorbDamage'
		// Here lies the not-yet-implemented method 'ShieldAbsorb'
		// Here lies the not-yet-implemented method 'AdjustDamage'
		// Here lies the not-yet-implemented method 'DropFlag'
		// Here lies the not-yet-implemented method 'EnableInventoryPickup'
		// Here lies the not-yet-implemented method 'HoldGameObject'
		// Here lies the not-yet-implemented method 'GiveHealth'
		// Here lies the not-yet-implemented method 'GetDebugName'
		// Here lies the not-yet-implemented method 'PlayFootStepSound'
		// Here lies the not-yet-implemented method 'ActuallyPlayFootstepSound'
		// Here lies the not-yet-implemented method 'GetMaterialBelowFeet'
		// Here lies the not-yet-implemented method 'PlayLandingSound'
		// Here lies the not-yet-implemented method 'PlayJumpingSound'
		// Here lies the not-yet-implemented method 'ShouldGib'
		// Here lies the not-yet-implemented method 'SpawnHeadGib'
		// Here lies the not-yet-implemented method 'SpawnGib'
		// Here lies the not-yet-implemented method 'SpawnGibs'
		// Here lies the not-yet-implemented method 'TurnOffPawn'
		// Here lies the not-yet-implemented method 'PlayDying'
		// Here lies the not-yet-implemented method 'DoingDeathAnim'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'AddDefaultInventory'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'SetThirdPersonCamera'
		// Here lies the not-yet-implemented method 'FindGoodEndView'
		// Here lies the not-yet-implemented method 'TryNewCamRot'
		// Here lies the not-yet-implemented method 'SetHeroCam'
		// Here lies the not-yet-implemented method 'CalcThirdPersonCam'
		// Here lies the not-yet-implemented method 'GetWeaponStartTraceLocation'
		// Here lies the not-yet-implemented method 'Dodge'
		// Here lies the not-yet-implemented method 'BotDodge'
		// Here lies the not-yet-implemented method 'PerformDodge'
		// Here lies the not-yet-implemented method 'DoDoubleJump'
		// Here lies the not-yet-implemented method 'Gasp'
		// Here lies the not-yet-implemented method 'StartFlying'
		// Here lies the not-yet-implemented method 'StopFlying'
		// Here lies the not-yet-implemented method 'DoJump'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'JumpOutOfWater'
		// Here lies the not-yet-implemented method 'CanMultiJump'
		// Here lies the not-yet-implemented method 'PlayDyingSound'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'SetPawnAmbientSound'
		// Here lies the not-yet-implemented method 'GetPawnAmbientSound'
		// Here lies the not-yet-implemented method 'SetWeaponAmbientSound'
		// Here lies the not-yet-implemented method 'GetWeaponAmbientSound'
		// Here lies the not-yet-implemented method 'SetOverlayMaterial'
		// Here lies the not-yet-implemented method 'GetShieldMaterialInstance'
		// Here lies the not-yet-implemented method 'GetOverlayMaterial'
		// Here lies the not-yet-implemented method 'SetWeaponOverlayFlag'
		// Here lies the not-yet-implemented method 'ClearWeaponOverlayFlag'
		// Here lies the not-yet-implemented method 'ApplyWeaponOverlayFlags'
		// Here lies the not-yet-implemented method 'StartFeignDeathRecoveryAnim'
		// Here lies the not-yet-implemented method 'FeignDeathDelayTimer'
		// Here lies the not-yet-implemented method 'PlayFeignDeath'
		// Here lies the not-yet-implemented method 'SetFeignEndLocation'
		// Here lies the not-yet-implemented method 'CheckValidLocation'
		// Here lies the not-yet-implemented method 'ServerFeignDeath'
		// Here lies the not-yet-implemented method 'FeignDeath'
		// Here lies the not-yet-implemented method 'ForceRagdoll'
		// Here lies the not-yet-implemented method 'FiringModeUpdated'
		// Here lies the not-yet-implemented method 'SetBigHead'
		// Here lies the not-yet-implemented method 'FireRateChanged'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'SetHeadScale'
		// Here lies the not-yet-implemented method 'SetPuttingDownWeapon'
		// Here lies the not-yet-implemented method 'GetPuttingDownWeapon'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'WeaponFired'
		// Here lies the not-yet-implemented method 'WeaponStoppedFiring'
		// Here lies the not-yet-implemented method 'WeaponChanged'
		// Here lies the not-yet-implemented method 'WeaponAttachmentChanged'
		// Here lies the not-yet-implemented method 'PlayHit'
		// Here lies the not-yet-implemented method 'PlayTakeHitEffects'
		// Here lies the not-yet-implemented method 'TakeHitBlendedOut'
		// Here lies the not-yet-implemented method 'ServerHoverboard'
		// Here lies the not-yet-implemented method 'OnUseHoverboard'
		// Here lies the not-yet-implemented method 'SwitchWeapon'
		// Here lies the not-yet-implemented method 'TakeDrowningDamage'
		// Here lies the not-yet-implemented method 'IsLocationOnHead'
		// Here lies the not-yet-implemented method 'ModifyRotForDebugFreeCam'
		// Here lies the not-yet-implemented method 'AdjustCameraScale'
		// Here lies the not-yet-implemented method 'GetViewRotation'
		// Here lies the not-yet-implemented method 'TornOff'
		// Here lies the not-yet-implemented method 'SetOverlayVisibility'
		// Here lies the not-yet-implemented method 'TakeFallingDamage'
		// Here lies the not-yet-implemented method 'RigidBodyCollision'
		// Here lies the not-yet-implemented method 'OnRanOver'
		// Here lies the not-yet-implemented method 'StuckFalling'
		// Here lies the not-yet-implemented method 'OnExitVehicle'
		// Here lies the not-yet-implemented method 'OnInfiniteAmmo'
		// Here lies the not-yet-implemented method 'PossessedBy'
		// Here lies the not-yet-implemented method 'NeedToTurn'
		// Here lies the not-yet-implemented method 'GetFamilyInfo'
		// Here lies the not-yet-implemented method 'PostTeleport'
		// Here lies the not-yet-implemented method 'PostBigTeleport'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
