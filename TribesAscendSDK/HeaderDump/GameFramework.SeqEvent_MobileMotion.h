#pragma once
#include "GameFramework.SeqEvent_MobileBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileMotion." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileMotion : public SeqEvent_MobileBase
	{
	public:
		ADD_VAR(::FloatProperty, DeltaYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeltaPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeltaRoll, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Yaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Pitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Roll, 0xFFFFFFFF)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_MobileMotion.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
