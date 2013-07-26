#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKAnimBlendByPhysicsVolume.PhysicsVolumeParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PhysicsVolumeParams
	{
	public:
		ADD_VAR(::FloatProperty, MaxGravity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinGravity, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCheckGravity, 0x2)
		ADD_VAR(::BoolProperty, bWaterVolume, 0x1)
		ADD_VAR(::IntProperty, ChildIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
