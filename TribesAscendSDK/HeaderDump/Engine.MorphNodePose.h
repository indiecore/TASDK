#pragma once
#include "Engine.MorphNodeBase.h"
#include "Engine.MorphTarget.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MorphNodePose : public MorphNodeBase
	{
	public:
		ADD_STRUCT(float, Weight, 120)
		ADD_STRUCT(ScriptName, MorphName, 112)
		ADD_OBJECT(MorphTarget, Target, 108)
		void SetMorphTarget(ScriptName MorphTargetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MorphNodePose.SetMorphTarget");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = MorphTargetName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
