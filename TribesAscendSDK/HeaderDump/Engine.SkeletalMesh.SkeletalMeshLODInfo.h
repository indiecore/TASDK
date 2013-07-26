#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMesh.SkeletalMeshLODInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkeletalMeshLODInfo
	{
	public:
		ADD_VAR(::FloatProperty, DisplayFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LODHysteresis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
