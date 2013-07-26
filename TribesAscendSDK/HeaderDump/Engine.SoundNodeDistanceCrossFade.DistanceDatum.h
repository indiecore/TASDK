#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SoundNodeDistanceCrossFade.DistanceDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty SoundNodeDistanceCrossFade.DistanceDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistanceDatum
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, FadeOutDistance, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, FadeInDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Volume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutDistanceEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutDistanceStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInDistanceEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInDistanceStart, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
