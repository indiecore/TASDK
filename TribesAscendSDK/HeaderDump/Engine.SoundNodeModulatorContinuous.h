#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.SoundNode.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeModulatorContinuous." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeModulatorContinuous : public SoundNode
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, VolumeModulation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, PitchModulation, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
