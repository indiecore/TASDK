#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_ConstantFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_ConstantFire." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_ConstantFire : public TrDevice
	{
	public:
		ADD_VAR(::NameProperty, m_PostFireState, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_FireTail)
		ADD_VAR(::FloatProperty, WeaponFireFadeTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsCurrentlyFiring, 0x4)
		ADD_VAR(::BoolProperty, m_bHasLoopingFireAnim, 0x2)
		ADD_VAR(::BoolProperty, m_bSoundLinkedWithState, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ConstantFire.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnEndConstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ConstantFire.OnEndConstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartConstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ConstantFire.OnStartConstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTickConstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ConstantFire.OnTickConstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ConstantFire.EndFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ConstantFire.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFireAnimation(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_ConstantFire.PlayFireAnimation");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
