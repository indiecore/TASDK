#pragma once
#include "Engine.AnimNodeBlendList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendBase : public AnimNodeBlendList
	{
	public:
		ADD_VAR(::BoolProperty, bTickAnimInScript, 0x1)
		ADD_VAR(::FloatProperty, BlendTime, 0xFFFFFFFF)
		float GetBlendTime(int ChildIndex, bool bGetDefault)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendBase.GetBlendTime");
			byte* params = (byte*)malloc(12);
			*(int*)params = ChildIndex;
			*(bool*)(params + 4) = bGetDefault;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float GetAnimDuration(int ChildIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendBase.GetAnimDuration");
			byte* params = (byte*)malloc(8);
			*(int*)params = ChildIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void TickAnim(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendBase.TickAnim");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
