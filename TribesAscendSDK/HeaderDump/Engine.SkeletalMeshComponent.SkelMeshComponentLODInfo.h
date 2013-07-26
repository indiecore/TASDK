#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMeshComponent.SkelMeshComponentLODInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelMeshComponentLODInfo
	{
	public:
		ADD_VAR(::ByteProperty, InstanceWeightUsage, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNeedsInstanceWeightUpdate, 0x1)
		ADD_VAR(::BoolProperty, bAlwaysUseInstanceWeights, 0x2)
		ADD_VAR(::IntProperty, InstanceWeightIdx, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
