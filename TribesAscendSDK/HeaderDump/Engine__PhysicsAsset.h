#pragma once
#include "Core__Object.h"
#include "Engine__PhysicsAssetInstance.h"
#include "Engine__SkeletalMesh.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PhysicsAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PhysicsAsset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PhysicsAsset : public Object
	{
	public:
		ADD_OBJECT(PhysicsAssetInstance, DefaultInstance)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'BodySetupIndexMap'!
		ADD_OBJECT(SkeletalMesh, DefaultSkelMesh)
		int FindBodyIndex(ScriptName BodyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAsset.FindBodyIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = BodyName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
