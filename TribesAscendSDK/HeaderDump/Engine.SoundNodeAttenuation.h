#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.SoundNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeAttenuation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeAttenuation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeAttenuation : public SoundNode
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, LPFMaxRadius, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, LPFMinRadius, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, MaxRadius, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, MinRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LPFRadiusMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LPFRadiusMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadiusMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadiusMin, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DistanceModel, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DistanceType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DistanceAlgorithm, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, dBAttenuationAtMax, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAttenuateWithLowPassFilter, 0x8)
		ADD_VAR(::BoolProperty, bAttenuateWithLPF, 0x4)
		ADD_VAR(::BoolProperty, bSpatialize, 0x2)
		ADD_VAR(::BoolProperty, bAttenuate, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
