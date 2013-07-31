#pragma once
#include "Engine.MorphNodeBase.h"
#include "Engine.MorphTarget.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MorphNodeMultiPose : public MorphNodeBase
	{
	public:
		ADD_STRUCT(ScriptArray<class MorphTarget*>, Targets, 108)
		ADD_STRUCT(ScriptArray<ScriptName>, MorphNames, 120)
		ADD_STRUCT(ScriptArray<float>, Weights, 132)
		bool AddMorphTarget(ScriptName MorphTargetName, float InWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20597);
			byte params[16] = { NULL };
			*(ScriptName*)params = MorphTargetName;
			*(float*)&params[8] = InWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void RemoveMorphTarget(ScriptName MorphTargetName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20601);
			byte params[8] = { NULL };
			*(ScriptName*)params = MorphTargetName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UpdateMorphTarget(class MorphTarget* Target, float InWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20603);
			byte params[12] = { NULL };
			*(class MorphTarget**)params = Target;
			*(float*)&params[4] = InWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_STRUCT
