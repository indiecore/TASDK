#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxTrPage_Vehicle.VehicleOption." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VehicleOption
	{
	public:
		ADD_VAR(::StrProperty, DisplayName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ClassName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Count, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Icon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Cost, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
