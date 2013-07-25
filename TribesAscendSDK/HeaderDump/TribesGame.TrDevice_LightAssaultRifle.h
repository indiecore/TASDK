#pragma once
#include "TribesGame.TrDevice_AssaultRifle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_LightAssaultRifle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_LightAssaultRifle : public TrDevice_AssaultRifle
	{
	public:
		ADD_VAR(::FloatProperty, m_fBurtShotRefireTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bHoldingFire, 0x1)
		ADD_VAR(::IntProperty, m_nShotsSoFar, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nShotBurstCount, 0xFFFFFFFF)
		void OnReloadComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LightAssaultRifle.OnReloadComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LightAssaultRifle.StopFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LightAssaultRifle.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefireTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LightAssaultRifle.RefireTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LightAssaultRifle.EndFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LightAssaultRifle.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFiringSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LightAssaultRifle.PlayFiringSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerStopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_LightAssaultRifle.ServerStopFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
