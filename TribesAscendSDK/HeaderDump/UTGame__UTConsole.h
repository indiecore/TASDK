#pragma once
#include "Engine__Console.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTConsole." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTConsole : public Console
	{
	public:
		ADD_VAR(::IntProperty, TextCount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'AnyBrowserOpen'
		// Here lies the not-yet-implemented method 'InputKey'
		// Here lies the not-yet-implemented method 'OutputTextLine'
	};
}
#undef ADD_VAR
