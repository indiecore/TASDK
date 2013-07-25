#pragma once
#include "Engine__PhysicsVolume.h"
#include "Engine__SoundCue.h"
#include "Engine__Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.WaterVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WaterVolume : public PhysicsVolume
	{
	public:
		ADD_OBJECT(ScriptClass, ExitActor)
		ADD_OBJECT(SoundCue, ExitSound)
		ADD_OBJECT(ScriptClass, EntryActor)
		ADD_OBJECT(SoundCue, EntrySound)
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'PlayEntrySplash'
		// Here lies the not-yet-implemented method 'UnTouch'
		// Here lies the not-yet-implemented method 'PlayExitSplash'
	};
}
#undef ADD_OBJECT
