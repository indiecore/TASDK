#pragma once
#include "Engine__MaterialInstanceConstant.h"
#include "UTGame__UTGameObjective.h"
#include "Engine__ParticleSystem.h"
#include "Engine__Controller.h"
#include "Engine__SoundCue.h"
#include "Engine__CameraAnim.h"
#include "Engine__PhysicsAsset.h"
#include "Engine__Texture2D.h"
#include "Engine__Material.h"
#include "TribesGame__TrStatsInterface.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#include "Engine__PlayerController.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameObjective." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameObjective : public UTGameObjective
	{
	public:
		ADD_OBJECT(ScriptClass, m_AssistAccolade)
		ADD_VAR(::FloatProperty, fUpgradeAssistTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMarker2DDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DESTROY_ASSIST_PERCENTAGE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, REPAIR_ASSIST_PERCENTAGE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInstigatorNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveHealthBarHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveHealthBarWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveHealthBarPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveHealthBarPlacementX, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_HealthBarMIC)
		ADD_VAR(::FloatProperty, m_fRepairBoost, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_UpgradeTemplate)
		ADD_VAR(::IntProperty, r_nUpgradeLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPromptMessageSwitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPromptMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_bReset, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, DestroyedTemplate)
		ADD_VAR(::FloatProperty, m_fLifeAfterDeathSecs, 0xFFFFFFFF)
		ADD_OBJECT(Controller, m_LastDamager)
		ADD_OBJECT(SoundCue, m_ExplosionSound)
		ADD_VAR(::BoolProperty, m_bAlwaysRelevantToSameTeam, 0x8000)
		ADD_VAR(::BoolProperty, m_bHurtByFriendlyFire, 0x4000)
		ADD_VAR(::BoolProperty, m_bDestroyable, 0x2000)
		ADD_VAR(::BoolProperty, m_bShowObjectivesForcesMarker, 0x1000)
		ADD_VAR(::BoolProperty, m_bIsRepairable, 0x800)
		ADD_VAR(::BoolProperty, m_bIsUpgradeable, 0x400)
		ADD_VAR(::BoolProperty, m_bHasPromptText, 0x200)
		ADD_VAR(::BoolProperty, r_bInDestroyedState, 0x100)
		ADD_VAR(::BoolProperty, m_bIsRepairableAfterDeath, 0x80)
		ADD_VAR(::BoolProperty, m_bPostRenderForEnemy, 0x40)
		ADD_VAR(::BoolProperty, m_bVisibilityRequiredForEnemy, 0x20)
		ADD_VAR(::BoolProperty, m_bForceShowHUD, 0x10)
		ADD_VAR(::BoolProperty, m_bReceivesPowerFromGenerator, 0x8)
		ADD_VAR(::BoolProperty, r_bIsPowered, 0x4)
		ADD_VAR(::BoolProperty, m_bInstantOnlineSound, 0x2)
		ADD_VAR(::BoolProperty, m_bAutoPlayOnlineSound, 0x1)
		ADD_OBJECT(PhysicsAsset, m_OfflinePhysicsAsset)
		ADD_OBJECT(PhysicsAsset, m_OnlinePhysicsAsset)
		ADD_OBJECT(ScriptClass, m_ExplosionLightClass)
		ADD_VAR(::StrProperty, m_sScreenName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOuterExplosionShakeRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInnerExplosionShakeRadius, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnim, m_ExplosionShake)
		ADD_OBJECT(ParticleSystem, m_ExplosionTemplate)
		ADD_VAR(::FloatProperty, m_fShieldHitRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShieldHitTargetTimeLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShieldHitTargetScale, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldMIC)
		ADD_VAR(::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MarkerOffset, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, m_ShieldNormalMap)
		ADD_OBJECT(Material, m_ShieldMaterial)
		ADD_VAR(::FloatProperty, m_fShieldHealthPercentage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nRepairHealthThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCriticalHealthThreshold, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, r_vReplicatedHitInfo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nHealthRegenRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_MaxHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_Health, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ObjectiveMIC)
		ADD_STRUCT(::VectorProperty, CallInPosition, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, CallInRotation, 0xFFFFFFFF)
		ADD_OBJECT(TrStatsInterface, Stats)
		bool IsEnemy(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.IsEnemy");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsInLOS_Basic(class Pawn* TouchedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.IsInLOS_Basic");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = TouchedPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetScreenName(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GetScreenName");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		float GetHealthAmount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GetHealthAmount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		int GetUpgradeCost(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GetUpgradeCost");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShouldShowPromptText(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ShouldShowPromptText");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Shootable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.Shootable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RegenerateHealth()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.RegenerateHealth");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoRepairs(int HealAmount, class Controller* EventInstigator, class Actor* DamageCauser, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.DoRepairs");
			byte* params = (byte*)malloc(44);
			*(int*)params = HealAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(class Actor**)(params + 8) = DamageCauser;
			*(ScriptClass**)(params + 12) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 16) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = DamageAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientRecievedHitInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ClientRecievedHitInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayUpgradeEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ClientPlayUpgradeEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDestroyedEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.PlayDestroyedEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnHealthChanged(bool wasDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.OnHealthChanged");
			byte* params = (byte*)malloc(4);
			*(bool*)params = wasDamage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDamageHealthEffects(int DamageAmount, int HitBoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.PlayDamageHealthEffects");
			byte* params = (byte*)malloc(8);
			*(int*)params = DamageAmount;
			*(int*)(params + 4) = HitBoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDamageShieldEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.PlayDamageShieldEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayExplosion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.PlayExplosion");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPowered(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.SetPowered");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.HideMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldPostRenderForCaH()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ShouldPostRenderForCaH");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
		bool GetPossessiveInstigatorName(ScriptArray<wchar_t>& PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GetPossessiveInstigatorName");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlayerName = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool BlocksLineChecksFromSourceActor(class Actor* SourceActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.BlocksLineChecksFromSourceActor");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = SourceActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnHelpTextCollisionProxy(byte HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.SpawnHelpTextCollisionProxy");
			byte* params = (byte*)malloc(1);
			*params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldShowHelpText(byte HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ShouldShowHelpText");
			byte* params = (byte*)malloc(5);
			*params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ReceivesPowerFromGenerator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ReceivesPowerFromGenerator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool PerformUpgrade(class TrPlayerController* Purchaser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.PerformUpgrade");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = Purchaser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddUpgrader(class TrPlayerController* Upgrader)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.AddUpgrader");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = Upgrader;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDamageAssistance(class TrPlayerController* TrPC, int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.AddDamageAssistance");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = TrPC;
			*(int*)(params + 4) = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckRepairAssists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.CheckRepairAssists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckDestroyAssists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.CheckDestroyAssists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearDamageAssistance(bool bOnlyDamagers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.ClearDamageAssistance");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bOnlyDamagers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GiveDestroyAccolade(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GiveDestroyAccolade");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSpectatorHealthInfo(int& Health, int& MaxHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GetSpectatorHealthInfo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Health;
			*(int*)(params + 4) = MaxHealth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Health = *(int*)params;
			MaxHealth = *(int*)(params + 4);
			free(params);
		}
		ScriptArray<wchar_t> GetSpectatorDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.GetSpectatorDescription");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool IsAliveAndWell()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.IsAliveAndWell");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void InstantlyRegenerateHealth()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.InstantlyRegenerateHealth");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideBasePlatform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.HideBasePlatform");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RequiresLOSForRepairDeployable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.RequiresLOSForRepairDeployable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void AwardKillAssists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.AwardKillAssists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AwardUpgradeAssists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.AwardUpgradeAssists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpgradePerformed(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameObjective.OnUpgradePerformed");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
