#pragma once
#include "Engine.ParticleModuleLocationBase.h"
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
	class ParticleModuleLocationEmitter : public ParticleModuleLocationBase
	{
	public:
		enum ELocationEmitterSelectionMethod : byte
		{
			ELESM_Random = 0,
			ELESM_Sequential = 1,
			ELESM_MAX = 2,
		};
		ADD_STRUCT(float, InheritSourceRotationScale, 92)
		ADD_STRUCT(float, InheritSourceVelocityScale, 88)
		ADD_BOOL(bInheritSourceRotation, 84, 0x2)
		ADD_BOOL(InheritSourceVelocity, 84, 0x1)
		ADD_STRUCT(ParticleModuleLocationEmitter::ELocationEmitterSelectionMethod, SelectionMethod, 80)
		ADD_STRUCT(ScriptName, EmitterName, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
