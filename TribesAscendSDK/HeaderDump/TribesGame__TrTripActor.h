#pragma once
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrTripActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTripActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTripActor : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, m_fSleepTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, r_Left)
		ADD_OBJECT(Actor, r_Right)
		ADD_VAR(::BoolProperty, m_bRequiresTwoNotifiers, 0x4)
		ADD_OBJECT(ParticleSystem, m_LaserTemplate)
		ADD_VAR(::FloatProperty, r_fSleepEndTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bIsInitialized, 0x2)
		ADD_VAR(::BoolProperty, r_bIsPowered, 0x1)
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'CreateTripComponent'
		// Here lies the not-yet-implemented method 'ClientCreateVisualEffect'
		// Here lies the not-yet-implemented method 'DestroyNotify'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'InitializeTripPhysics'
		// Here lies the not-yet-implemented method 'GoToSleep'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'Touch'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
