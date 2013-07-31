#pragma once
#include "TribesGame.TrDevice.h"
#include "TribesGame.TrPawn.h"
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
	class TrDevice_Pack : public TrDevice
	{
	public:
		struct PowerPoolCostInfo
		{
		public:
			ADD_OBJECT(ScriptClass, m_TrFamilyInfo, 4)
			ADD_STRUCT(float, m_fPowerPoolCostPerSec, 0)
		};
		ADD_STRUCT(ScriptArray<TrDevice_Pack::PowerPoolCostInfo>, m_PowerPoolInfo, 2152)
		ADD_STRUCT(float, m_CachedPowerPoolCostPerSec, 2164)
		ADD_STRUCT(float, m_fDefaultPowerPoolCostPerSec, 2148)
		bool UsesPower()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80672);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float GetPowerPool(class TrPawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80674);
			byte params[8] = { NULL };
			*(class TrPawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool CanBeActive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80678);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ConsumePowerPool(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80681);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleActivate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80688);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerToggleActivate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80689);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceActivate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80690);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientForceActive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80691);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientForceInactive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80692);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80704);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80706);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendToFiringState(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80708);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
