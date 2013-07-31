#pragma once
#include "Engine.ParticleModuleEventBase.h"
#include "Engine.ParticleSystemComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleEventReceiverBase : public ParticleModuleEventBase
	{
	public:
		ADD_STRUCT(ScriptName, EventName, 76)
		ADD_STRUCT(ParticleSystemComponent::EParticleEventType, EventGeneratorType, 72)
	};
}
#undef ADD_STRUCT
