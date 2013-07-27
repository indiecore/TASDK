#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.ParticleSystemComponent.h"
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
	class SeqAct_SetParticleSysParam : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<ParticleSystemComponent::ParticleSysParam>, InstanceParameters, 232)
		ADD_BOOL(bOverrideScalar, 244, 0x1)
		ADD_STRUCT(float, ScalarValue, 248)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
