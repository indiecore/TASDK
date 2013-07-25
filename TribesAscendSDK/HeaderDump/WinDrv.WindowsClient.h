#pragma once
#include "Engine.Client.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WinDrv.WindowsClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty WinDrv.WindowsClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WindowsClient : public Client
	{
	public:
		ADD_OBJECT(ScriptClass, AudioDeviceClass)
		ADD_VAR(::IntProperty, AllowJoystickInput, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
