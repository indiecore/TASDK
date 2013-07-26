#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.Object.Vector.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " LensFlare.LensFlareElement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty LensFlare.LensFlareElement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LensFlareElement
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, DistMap_Alpha, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, DistMap_Color, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, DistMap_Scale, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, Offset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Alpha, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, Color, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOrientTowardsSource, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Rotation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, AxisScaling, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Scaling, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, LFMaterialIndex, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Size, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bModulateColorBySource, 0x8)
		ADD_VAR(::BoolProperty, bNormalizeRadialDistance, 0x4)
		ADD_VAR(::BoolProperty, bUseSourceDistance, 0x2)
		ADD_VAR(::BoolProperty, bIsEnabled, 0x1)
		ADD_VAR(::FloatProperty, RayDistance, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ElementName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
