#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileLook." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.SeqEvent_MobileLook." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileLook : public SeqEvent_MobileZoneBase
	{
	public:
		ADD_STRUCT(::VectorProperty, RotationVector, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, StickStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Yaw, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
