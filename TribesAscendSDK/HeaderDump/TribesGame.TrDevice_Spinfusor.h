#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.SoundCue.h"
#include "Engine.SkelControlSingleBone.h"
#include "TribesGame.TrSkelControl_SpinControl.h"
#include "Engine.AnimNodeSequence.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_Spinfusor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_Spinfusor : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_SpinfusorIdleSound)
		ADD_OBJECT(SkelControlSingleBone, m_DiscVisibilityControl)
		ADD_OBJECT(TrSkelControl_SpinControl, m_DiscSpinControl)
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.UpdateReplicatedCarriedAmmo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAnimPlay(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.OnAnimPlay");
			byte* params = (byte*)malloc(4);
			*(class AnimNodeSequence**)params = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.PlayFireEffects");
			byte* params = (byte*)malloc(13);
			*params = FireModeNum;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.PlayWeaponEquip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDiscVisibility(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.SetDiscVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDiscSpinning(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.SetDiscSpinning");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.PlayWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownFast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.PutDownFast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Spinfusor.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
