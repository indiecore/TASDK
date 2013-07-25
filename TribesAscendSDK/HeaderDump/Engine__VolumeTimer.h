#pragma once
#include "Engine__Info.h"
#include "Engine__PhysicsVolume.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.VolumeTimer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VolumeTimer : public Info
	{
	public:
		ADD_OBJECT(PhysicsVolume, V)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Timer'
	};
}
#undef ADD_OBJECT
