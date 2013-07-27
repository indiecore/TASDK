#pragma once
#include "Core.Object.h"
#include "Engine.MorphTarget.h"
#include "Engine.SkeletalMesh.h"
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
	class MorphTargetSet : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class MorphTarget*>, Targets, 60)
		ADD_STRUCT(Object::Array_Mirror, RawWedgePointIndices, 76)
		ADD_OBJECT(SkeletalMesh, BaseSkelMesh, 72)
		class MorphTarget* FindMorphTarget(ScriptName MorphTargetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MorphTargetSet.FindMorphTarget");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = MorphTargetName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MorphTarget**)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
