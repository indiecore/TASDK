#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleBeamBase.h"
#include "Engine.ParticleModuleBeamModifier.BeamModifierOptions.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleBeamModifier." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleBeamModifier." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleBeamModifier : public ParticleModuleBeamBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Strength, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<BeamModifierOptions>, StrengthOptions, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAbsoluteTangent, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, Tangent, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<BeamModifierOptions>, TangentOptions, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, Position, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<BeamModifierOptions>, PositionOptions, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ModifierType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
