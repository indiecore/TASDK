#pragma once
#include "TribesGame__TrDevice.h"
#include "Engine__SoundCue.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_SpikeLauncher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_SpikeLauncher : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_SpikeIdleSound)
		void SetSpikeIdle(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SpikeLauncher.SetSpikeIdle");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SpikeLauncher.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAnimPlay(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SpikeLauncher.OnAnimPlay");
			byte* params = (byte*)malloc(4);
			*(class AnimNodeSequence**)params = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SpikeLauncher.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SpikeLauncher.PlayWeaponEquip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SpikeLauncher.PlayWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownFast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SpikeLauncher.PutDownFast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SpikeLauncher.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
