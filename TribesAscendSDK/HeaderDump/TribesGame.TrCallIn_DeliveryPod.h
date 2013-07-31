#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.MaterialInstanceTimeVarying.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
#include "TribesGame.TrCallIn_CrashLandInfo.h"
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
	class TrCallIn_DeliveryPod : public Actor
	{
	public:
		ADD_STRUCT(float, Speed, 520)
		ADD_STRUCT(Vector, TargetImpactPoint, 536)
		ADD_STRUCT(Vector, TargetHitNormal, 524)
		ADD_STRUCT(float, LifeAfterImpact, 516)
		ADD_OBJECT(SoundCue, ImpactSound, 512)
		ADD_OBJECT(SoundCue, FallingSound, 508)
		ADD_OBJECT(ParticleSystem, DeliveryPodImpactTemplate, 500)
		ADD_OBJECT(ParticleSystem, DeliveryPodParticleTemplate, 492)
		ADD_STRUCT(float, DecalDissolveTime, 488)
		ADD_STRUCT(float, HitDecalWidth, 484)
		ADD_STRUCT(float, HitDecalHeight, 480)
		ADD_OBJECT(MaterialInstanceTimeVarying, PodHitDecal, 476)
		float GetTerminalVelocity()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74035);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void Init(class TrCallIn_CrashLandInfo* CrashInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74037);
			byte params[4] = { NULL };
			*(class TrCallIn_CrashLandInfo**)params = CrashInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakApart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74039);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74042);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74044);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74046);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74047);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
