#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.CompartmentRunList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CompartmentRunList
	{
	public:
		ADD_VAR(::BoolProperty, RigidBody, 0x1)
		ADD_VAR(::BoolProperty, Fluid, 0x2)
		ADD_VAR(::BoolProperty, Cloth, 0x4)
		ADD_VAR(::BoolProperty, SoftBody, 0x8)
	};
}
#undef ADD_VAR
