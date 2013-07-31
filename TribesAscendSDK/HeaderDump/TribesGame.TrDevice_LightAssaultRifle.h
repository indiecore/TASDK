#pragma once
#include "TribesGame.TrDevice_AssaultRifle.h"
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
namespace UnrealScript
{
	class TrDevice_LightAssaultRifle : public TrDevice_AssaultRifle
	{
	public:
		ADD_STRUCT(float, m_fBurtShotRefireTime, 2184)
		ADD_BOOL(m_bHoldingFire, 2180, 0x1)
		ADD_STRUCT(int, m_nShotsSoFar, 2176)
		ADD_STRUCT(int, m_nShotBurstCount, 2172)
		void OnReloadComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83025);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83026);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83028);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefireTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83030);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83031);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83033);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFiringSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83034);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerStopFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(83035);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
