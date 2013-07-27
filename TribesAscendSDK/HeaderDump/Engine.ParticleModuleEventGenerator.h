#pragma once
#include "Engine.ParticleModuleEventBase.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleEventGenerator : public ParticleModuleEventBase
	{
	public:
		struct ParticleEvent_GenerateInfo
		{
		public:
			ADD_STRUCT(ScriptArray<class ParticleModuleEventSendToGame*>, ParticleModuleEventsToSendToGame, 28)
			ADD_STRUCT(ScriptName, CustomName, 20)
			ADD_BOOL(UseReflectedImpactVector, 16, 0x4)
			ADD_BOOL(LastTimeOnly, 16, 0x2)
			ADD_BOOL(FirstTimeOnly, 16, 0x1)
			ADD_STRUCT(int, ParticleFrequency, 12)
			ADD_STRUCT(int, LowFreq, 8)
			ADD_STRUCT(int, Frequency, 4)
			ADD_STRUCT(ParticleSystemComponent::EParticleEventType, Type, 0)
		};
		ADD_STRUCT(ScriptArray<ParticleModuleEventGenerator::ParticleEvent_GenerateInfo>, Events, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
