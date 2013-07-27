#pragma once
#include "Core.Object.h"
#include "TribesGame.TrGameObjective.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.Texture2D.h"
#include "TribesGame.TrTeamBlockerStaticMeshActor.h"
#include "TribesGame.TrHelpTextManager.h"
#include "Engine.AnimNodeScalePlayRate.h"
#include "TribesGame.TrDeployable.h"
#include "TribesGame.TrPlayerController.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrPowerGenerator : public TrGameObjective
	{
	public:
		ADD_STRUCT(ScriptArray<class TrGameObjective*>, m_PoweredObjectives, 1384)
		ADD_STRUCT(ScriptArray<class TrTeamBlockerStaticMeshActor*>, m_PoweredTeamBlockers, 1404)
		ADD_STRUCT(float, m_fAnimInterpSpeed, 1400)
		ADD_OBJECT(AnimNodeScalePlayRate, m_AnimNodeScale, 1396)
		ADD_STRUCT(float, m_fAutoRestoreHealthEffectsInterpSpeed, 1380)
		ADD_STRUCT(float, m_fAutoRestoreHealthTimeStamp, 1376)
		ADD_STRUCT(int, r_nDowntimeRemaining, 1372)
		ADD_BOOL(m_bFullyRestoringHealthEffects, 1368, 0x2)
		ADD_BOOL(m_bAutoRestoreHealthEnabled, 1368, 0x1)
		ADD_STRUCT(float, m_fAutoRestoreHealthTime, 1364)
		ADD_STRUCT(float, m_fMaxMorphDamage, 1360)
		bool IsGeneratingPower()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79907);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107459);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107463);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldShowHelpText(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107465);
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107468);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107470);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107472);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDamageHealthEffects(int DamageAmount, int HitBoneIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107474);
			byte params[8] = { NULL };
			*(int*)params = DamageAmount;
			*(int*)&params[4] = HitBoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoRepairs(int HealAmount, class Controller* EventInstigator, class Actor* DamageCauser, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107481);
			byte params[44] = { NULL };
			*(int*)params = HealAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(class Actor**)&params[8] = DamageCauser;
			*(ScriptClass**)&params[12] = DamageType;
			*(Actor::TraceHitInfo*)&params[16] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DamageAllMorphs(float DamageAmount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107487);
			byte params[4] = { NULL };
			*(float*)params = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRestoreHealthEffects(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107493);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGeneratorDowntime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107500);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateGeneratorPower(bool bPowered)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107502);
			byte params[4] = { NULL };
			*(bool*)params = bPowered;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AutoRestoreHealth(bool bFullyRestore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107508);
			byte params[4] = { NULL };
			*(bool*)params = bFullyRestore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddToPoweredObjectives(class TrDeployable* dep)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107528);
			byte params[4] = { NULL };
			*(class TrDeployable**)params = dep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107530);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107542);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
		void GiveDestroyAccolade(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107544);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AwardUpgradeAssists()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107546);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
