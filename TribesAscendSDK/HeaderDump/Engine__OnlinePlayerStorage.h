#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlinePlayerStorage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlinePlayerStorage : public Object
	{
	public:
		ADD_VAR(::IntProperty, DeviceID, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AsyncState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VersionNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VersionSettingsId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
