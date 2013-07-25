#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.Projectile.h"
#include "Engine.AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_AutoFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_AutoFire." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_AutoFire : public TrDevice
	{
	public:
		ADD_VAR(::BoolProperty, m_bPullPinFire, 0x1)
		ADD_VAR(::FloatProperty, m_fPullPinTime, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_PostFireDevice)
		ADD_VAR(::FloatProperty, m_fBuildupTime, 0xFFFFFFFF)
		float GetBuildUpTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.GetBuildUpTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetEquipTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.GetEquipTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetPutDownTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.GetPutDownTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void PlayFireAnimation(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.PlayFireAnimation");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.AddCarriedAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void PerformInactiveReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.PerformInactiveReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.HasAmmo");
			byte* params = (byte*)malloc(9);
			*params = FireModeNum;
			*(int*)(params + 4) = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPostFireDevice(class TrDevice* PostFireDevice)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.SetPostFireDevice");
			byte* params = (byte*)malloc(4);
			*(class TrDevice**)params = PostFireDevice;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchToPostFireDevice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.SwitchToPostFireDevice");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanFireNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.CanFireNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool DoOverrideNextWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.DoOverrideNextWeapon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool DoOverridePrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.DoOverridePrevWeapon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanAutoDeviceFireNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.CanAutoDeviceFireNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RequestReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.RequestReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnClientReloaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.OnClientReloaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientFinishedReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.ClientFinishedReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReloadComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.OnReloadComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void IncrementFlashCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.IncrementFlashCount");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanViewZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.CanViewZoom");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.ConsumeAmmo");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConsumeAmmo_Internal(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.ConsumeAmmo_Internal");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AutoFire.HolderEnteredVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
