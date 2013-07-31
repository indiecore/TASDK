#pragma once
#include "Engine.MorphNodeWeightBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MorphNodeWeight : public MorphNodeWeightBase
	{
	public:
		ADD_STRUCT(float, NodeWeight, 120)
		void SetNodeWeight(float NewWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20620);
			byte params[4] = { NULL };
			*(float*)params = NewWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
