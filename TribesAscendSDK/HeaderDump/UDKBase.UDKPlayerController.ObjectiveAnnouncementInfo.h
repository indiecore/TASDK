#pragma once
#include "Engine.SoundNodeWave.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKPlayerController.ObjectiveAnnouncementInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKPlayerController.ObjectiveAnnouncementInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ObjectiveAnnouncementInfo
	{
	public:
		ADD_VAR(::StrProperty, AnnouncementText, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, AnnouncementSound)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
