#pragma once
#include "Engine.AnimNodeBlendPerBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByWeapon : public AnimNodeBlendPerBone
	{
	public:
		ADD_VAR(::FloatProperty, BlendTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LoopingAnim, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLooping, 0x1)
		void AnimFire(ScriptName FireSequence, bool bAutoFire, float AnimRate, float SpecialBlendTime, ScriptName LoopSequence)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendByWeapon.AnimFire");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = FireSequence;
			*(bool*)(params + 8) = bAutoFire;
			*(float*)(params + 12) = AnimRate;
			*(float*)(params + 16) = SpecialBlendTime;
			*(ScriptName*)(params + 20) = LoopSequence;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AnimStopFire(float SpecialBlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendByWeapon.AnimStopFire");
			byte* params = (byte*)malloc(4);
			*(float*)params = SpecialBlendTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
