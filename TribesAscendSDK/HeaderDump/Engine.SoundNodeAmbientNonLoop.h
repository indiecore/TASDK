#pragma once
#include "Engine.SoundNodeAmbient.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeAmbientNonLoop." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeAmbientNonLoop." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeAmbientNonLoop : public SoundNodeAmbient
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, DelayTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DelayMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DelayMin, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
