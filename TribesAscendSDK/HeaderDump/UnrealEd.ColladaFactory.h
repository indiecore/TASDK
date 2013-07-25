#pragma once
#include "Core.Factory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UnrealEd.ColladaFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ColladaFactory : public Factory
	{
	public:
		ADD_VAR(::BoolProperty, bImportAsSkeletalMesh, 0x1)
	};
}
#undef ADD_VAR
