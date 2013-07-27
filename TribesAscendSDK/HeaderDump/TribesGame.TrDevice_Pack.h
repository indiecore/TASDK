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
		class PowerPoolCostInfo
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.UsesPower");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float GetPowerPool(class TrPawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.GetPowerPool");
			byte params[8] = { NULL };
			*(class TrPawn**)&params[0] = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool CanBeActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.CanBeActive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ConsumePowerPool(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.ConsumePowerPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleActivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.ToggleActivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerToggleActivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.ServerToggleActivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceActivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.ForceActivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientForceActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.ClientForceActive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientForceInactive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.ClientForceInactive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.StopFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendToFiringState(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Pack.SendToFiringState");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
