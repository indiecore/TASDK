#pragma once
#include "TribesGame__TrDevice_ConstantFire.h"
#include "Engine__PlayerReplicationInfo.h"
#include "TribesGame__TrSkelControl_SpinControl.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_ChainGun." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_ChainGun." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_ChainGun : public TrDevice_ConstantFire
	{
	public:
		ADD_VAR(::BoolProperty, m_bHasClip, 0x1)
		ADD_VAR(::IntProperty, r_BuffedMaxAmmo, 0xFFFFFFFF)
		ADD_OBJECT(TrSkelControl_SpinControl, m_BarrelSpinControl)
		ADD_VAR(::FloatProperty, m_fCurrSpinTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBuildupTime, 0xFFFFFFFF)
		float GetBuildUpTime(class PlayerReplicationInfo* PRI, bool bForInterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.GetBuildUpTime");
			byte* params = (byte*)malloc(12);
			*(class PlayerReplicationInfo**)params = PRI;
			*(bool*)(params + 4) = bForInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSoundModulation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.UpdateSoundModulation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayBuildupAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.PlayBuildupAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.OnSwitchToWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.PlayWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BuffMaxCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.BuffMaxCarriedAmmo");
			byte* params = (byte*)malloc(4);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.AddCarriedAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetBasePickupAmmoAmount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ChainGun.GetBasePickupAmmoAmount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
