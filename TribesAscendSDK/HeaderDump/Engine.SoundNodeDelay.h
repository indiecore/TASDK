#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.SoundNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeDelay." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeDelay." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeDelay : public SoundNode
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, DelayDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DelayMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DelayMin, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
