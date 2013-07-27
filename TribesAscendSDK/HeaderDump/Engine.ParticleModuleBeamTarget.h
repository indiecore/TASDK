#pragma once
#include "Engine.ParticleModuleBeamBase.h"
#include "Core.DistributionVector.h"
#include "Core.DistributionFloat.h"
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
	class ParticleModuleBeamTarget : public ParticleModuleBeamBase
	{
	public:
		ADD_STRUCT(float, LockRadius, 172)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, TargetStrength, 144)
		ADD_STRUCT(DistributionVector::RawDistributionVector, TargetTangent, 116)
		ADD_BOOL(bLockTargetStength, 112, 0x8)
		ADD_BOOL(bLockTargetTangent, 112, 0x4)
		ADD_BOOL(bLockTarget, 112, 0x2)
		ADD_BOOL(bTargetAbsolute, 112, 0x1)
		ADD_STRUCT(DistributionVector::RawDistributionVector, Target, 84)
		ADD_STRUCT(ScriptName, TargetName, 76)
		ADD_STRUCT(ParticleModuleBeamBase::Beam2SourceTargetTangentMethod, TargetTangentMethod, 73)
		ADD_STRUCT(ParticleModuleBeamBase::Beam2SourceTargetMethod, TargetMethod, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
