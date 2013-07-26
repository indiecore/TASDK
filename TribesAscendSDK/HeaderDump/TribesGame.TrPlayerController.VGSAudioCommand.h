#pragma once
#include "Engine.SoundCue.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrPlayerController.VGSAudioCommand." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VGSAudioCommand
	{
	public:
		ADD_OBJECT(SoundCue, QueuedSoundCue)
		ADD_OBJECT(TrPlayerReplicationInfo, VGSInstigator)
	};
}
#undef ADD_OBJECT
