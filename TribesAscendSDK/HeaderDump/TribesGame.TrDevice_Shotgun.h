#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.AnimNodePlayCustomAnim.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.AnimNodeSequence.h"
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
	class TrDevice_Shotgun : public TrDevice
	{
	public:
		ADD_OBJECT(AnimNodePlayCustomAnim, ReloadCustomAnimNode, 2172)
		ADD_STRUCT(int, m_nConsumeShotsFired, 2168)
		ADD_STRUCT(int, m_nShotsFired, 2164)
		ADD_STRUCT(float, m_fInnerDefaultAccuracy, 2160)
		ADD_STRUCT(float, m_fConsumeAmmoTimeStamp, 2156)
		ADD_STRUCT(int, m_nImpactCounter, 2152)
		ADD_STRUCT(int, m_nMinShotCount, 2148)
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80619);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlashLocation(Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80621);
			byte params[12] = { NULL };
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PerformInactiveReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80623);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CustomFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80625);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80627);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80628);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80630);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumeAmmo_Internal(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80632);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessInstantHit_Internal(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80634);
			byte params[85] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80638);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
