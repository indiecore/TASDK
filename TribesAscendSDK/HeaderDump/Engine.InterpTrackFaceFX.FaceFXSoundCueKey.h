#pragma once
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty InterpTrackFaceFX.FaceFXSoundCueKey." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FaceFXSoundCueKey
	{
	public:
		ADD_OBJECT(SoundCue, FaceFXSoundCue)
	};
}
#undef ADD_OBJECT
