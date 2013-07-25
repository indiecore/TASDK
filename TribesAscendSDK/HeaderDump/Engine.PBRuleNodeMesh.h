#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PBRuleNodeMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeMesh : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::BoolProperty, bBlockAll, 0x2)
		ADD_VAR(::BoolProperty, bDoOcclusionTest, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PBRuleNodeMesh.BuildingMeshInfo' for the property named 'PartialOccludedBuildingMesh'!
		int PickRandomBuildingMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PBRuleNodeMesh.PickRandomBuildingMesh");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
