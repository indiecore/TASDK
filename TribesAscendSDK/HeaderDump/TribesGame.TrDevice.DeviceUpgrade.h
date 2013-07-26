#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrDevice.DeviceUpgrade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DeviceUpgrade
	{
	public:
		ADD_VAR(::IntProperty, DatabaseItemId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
