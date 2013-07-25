#pragma once
#include "UnrealEd.SkeletalMeshFactory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UnrealEd.ReimportSkeletalMeshFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ReimportSkeletalMeshFactory : public SkeletalMeshFactory
	{
	public:
		ADD_VAR(::BoolProperty, bAssumeMayaCoordinates, 0x1)
	};
}
#undef ADD_VAR
