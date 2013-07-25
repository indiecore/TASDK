#pragma once
#include "UnrealEd.StaticMeshFactory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UnrealEd.ReimportStaticMeshFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ReimportStaticMeshFactory : public StaticMeshFactory
	{
	public:
		ADD_VAR(::IntProperty, Pitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Roll, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Yaw, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOneConvexPerUCXObject, 0x1)
		ADD_VAR(::BoolProperty, bSingleSmoothGroupSingleTangent, 0x1)
	};
}
#undef ADD_VAR
