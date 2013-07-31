#pragma once
#include "Engine.RB_ConstraintSetup.h"
#include "Core.Object.h"
#include "Engine.PhysicsAssetInstance.h"
#include "Engine.RB_BodySetup.h"
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
	class PhysicsAsset : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class RB_ConstraintSetup*>, ConstraintSetup, 148)
		ADD_STRUCT(ScriptArray<class RB_BodySetup*>, BodySetup, 64)
		ADD_STRUCT(ScriptArray<int>, BoundsBodies, 136)
		ADD_OBJECT(PhysicsAssetInstance, DefaultInstance, 160)
		ADD_STRUCT(Object::Map_Mirror, BodySetupIndexMap, 76)
		ADD_OBJECT(SkeletalMesh, DefaultSkelMesh, 60)
		int FindBodyIndex(ScriptName BodyName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24337);
			byte params[12] = { NULL };
			*(ScriptName*)params = BodyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
