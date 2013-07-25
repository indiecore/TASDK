#pragma once
#include "UDKBase__UDKPickupFactory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPickupFactory : public UDKPickupFactory
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, PickUpWaveForm)
		ADD_VAR(::FloatProperty, LastSeekNotificationTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasLocationSpeech, 0x1)
		ADD_VAR(::NameProperty, PickupStatName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, RespawnSound)
		ADD_OBJECT(Controller, TeamOwner)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
