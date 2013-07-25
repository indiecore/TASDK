#pragma once
#include "Engine__SoundNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeModulator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeModulator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeModulator : public SoundNode
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'VolumeModulation'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'PitchModulation'!
		ADD_VAR(::FloatProperty, VolumeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VolumeMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchMin, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
