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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlashLocation(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.SetFlashLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PerformInactiveReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.PerformInactiveReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CustomFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.CustomFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.ConsumeAmmo");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumeAmmo_Internal(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.ConsumeAmmo_Internal");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessInstantHit_Internal(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.ProcessInstantHit_Internal");
			byte params[85] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Shotgun.OnAnimEnd");
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
