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
	class ParticleModuleBeamModifier : public ParticleModuleBeamBase
	{
	public:
		enum BeamModifierType : byte
		{
			PEB2MT_Source = 0,
			PEB2MT_Target = 1,
			PEB2MT_MAX = 2,
		};
		class BeamModifierOptions
		{
		public:
			ADD_BOOL(Block, 0, 0x4)
			ADD_BOOL(bScale, 0, 0x2)
			ADD_BOOL(bModify, 0, 0x1)
		};
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Strength, 148)
		ADD_STRUCT(ParticleModuleBeamModifier::BeamModifierOptions, StrengthOptions, 144)
		ADD_BOOL(bAbsoluteTangent, 140, 0x1)
		ADD_STRUCT(DistributionVector::RawDistributionVector, Tangent, 112)
		ADD_STRUCT(ParticleModuleBeamModifier::BeamModifierOptions, TangentOptions, 108)
		ADD_STRUCT(DistributionVector::RawDistributionVector, Position, 80)
		ADD_STRUCT(ParticleModuleBeamModifier::BeamModifierOptions, PositionOptions, 76)
		ADD_STRUCT(ParticleModuleBeamModifier::BeamModifierType, ModifierType, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
