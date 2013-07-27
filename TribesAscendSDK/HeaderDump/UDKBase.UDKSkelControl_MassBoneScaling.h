#pragma once
#include "Engine.SkelControlBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_MassBoneScaling : public SkelControlBase
	{
	public:
		ADD_STRUCT(ScriptArray<float>, BoneScales, 188)
		void SetBoneScale(ScriptName BoneName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKSkelControl_MassBoneScaling.SetBoneScale");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetBoneScale(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKSkelControl_MassBoneScaling.GetBoneScale");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
#undef ADD_STRUCT
