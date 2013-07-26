#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMesh.SoftBodyTetraLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty SkeletalMesh.SoftBodyTetraLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoftBodyTetraLink
	{
	public:
		ADD_VAR(::IntProperty, Index, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Bary, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
