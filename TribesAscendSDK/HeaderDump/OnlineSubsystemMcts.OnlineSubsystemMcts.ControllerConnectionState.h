#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystemMcts.ControllerConnectionState." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ControllerConnectionState
	{
	public:
		ADD_VAR(::IntProperty, bLastIsControllerConnected, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bIsControllerConnected, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
