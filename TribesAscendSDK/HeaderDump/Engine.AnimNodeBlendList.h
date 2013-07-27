#pragma once
#include "Engine.AnimNodeBlendBase.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendList : public AnimNodeBlendBase
	{
	public:
		ADD_STRUCT(ScriptArray<float>, TargetWeight, 244)
		ADD_STRUCT(int, EditorActiveChildIndex, 272)
		ADD_STRUCT(float, SliderPosition, 268)
		ADD_BOOL(bSkipBlendWhenNotRendered, 264, 0x4)
		ADD_BOOL(bForceChildFullWeightWhenBecomingRelevant, 264, 0x2)
		ADD_BOOL(bPlayActiveChild, 264, 0x1)
		ADD_STRUCT(int, ActiveChildIndex, 260)
		ADD_STRUCT(float, BlendTimeToGo, 256)
		void SetActiveChild(int ChildIndex, float BlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeBlendList.SetActiveChild");
			byte params[8] = { NULL };
			*(int*)&params[0] = ChildIndex;
			*(float*)&params[4] = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
