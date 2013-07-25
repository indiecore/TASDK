#pragma once
#include "Engine.SoundNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeLooping." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeLooping." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeLooping : public SoundNode
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'LoopCount'!
		ADD_VAR(::FloatProperty, LoopCountMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LoopCountMin, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLoopIndefinitely, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
