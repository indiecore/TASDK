#pragma once
#include "TribesGame__TrGameObjective.h"
#include "Engine__Controller.h"
#include "Engine__AnimNodeScalePlayRate.h"
#include "Engine__Actor.h"
#include "TribesGame__TrDeployable.h"
#include "Engine__Texture2D.h"
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPowerGenerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPowerGenerator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPowerGenerator : public TrGameObjective
	{
	public:
		ADD_VAR(::FloatProperty, m_fAnimInterpSpeed, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeScalePlayRate, m_AnimNodeScale)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthEffectsInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nDowntimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bFullyRestoringHealthEffects, 0x2)
		ADD_VAR(::BoolProperty, m_bAutoRestoreHealthEnabled, 0x1)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxMorphDamage, 0xFFFFFFFF)
		bool IsGeneratingPower()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.IsGeneratingPower");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldShowHelpText(byte HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.ShouldShowHelpText");
			byte* params = (byte*)malloc(5);
			*params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDamageHealthEffects(int DamageAmount, int HitBoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.PlayDamageHealthEffects");
			byte* params = (byte*)malloc(8);
			*(int*)params = DamageAmount;
			*(int*)(params + 4) = HitBoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoRepairs(int HealAmount, class Controller* EventInstigator, class Actor* DamageCauser, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.DoRepairs");
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
		void DamageAllMorphs(float DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.DamageAllMorphs");
			byte* params = (byte*)malloc(4);
			*(float*)params = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayRestoreHealthEffects(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.PlayRestoreHealthEffects");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGeneratorDowntime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.UpdateGeneratorDowntime");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateGeneratorPower(bool bPowered)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.UpdateGeneratorPower");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPowered;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AutoRestoreHealth(bool bFullyRestore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.AutoRestoreHealth");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bFullyRestore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddToPoweredObjectives(class TrDeployable* dep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.AddToPoweredObjectives");
			byte* params = (byte*)malloc(4);
			*(class TrDeployable**)params = dep;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.TakeDamage");
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
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
		void GiveDestroyAccolade(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.GiveDestroyAccolade");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AwardUpgradeAssists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPowerGenerator.AwardUpgradeAssists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
