#pragma once
#include "Engine__ParticleModuleBeamBase.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Strength'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModuleBeamModifier.BeamModifierOptions' for the property named 'StrengthOptions'!
		ADD_VAR(::BoolProperty, bAbsoluteTangent, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'Tangent'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModuleBeamModifier.BeamModifierOptions' for the property named 'TangentOptions'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'Position'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModuleBeamModifier.BeamModifierOptions' for the property named 'PositionOptions'!
		ADD_VAR(::ByteProperty, ModifierType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
