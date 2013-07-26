#pragma once
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrAnimNotify_Sound.DeviceOverride." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DeviceOverride
	{
	public:
		ADD_OBJECT(ScriptClass, DeviceClass)
		ADD_OBJECT(SoundCue, SoundCue)
	};
}
#undef ADD_OBJECT
