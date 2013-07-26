#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.VehicleAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VehicleAnim
	{
	public:
		ADD_VAR(::NameProperty, AnimPlayerName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAnimLoopLastSeq, 0x1)
		ADD_VAR(::FloatProperty, AnimRate, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimTag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
