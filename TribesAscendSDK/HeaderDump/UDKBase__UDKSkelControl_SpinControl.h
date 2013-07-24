#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_SpinControl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKSkelControl_SpinControl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_SpinControl : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(::VectorProperty, Axis, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, DegreesPerSecond, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
