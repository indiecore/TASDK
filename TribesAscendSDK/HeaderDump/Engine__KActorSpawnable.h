#pragma once
#include "Engine__KActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KActorSpawnable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KActorSpawnable : public KActor
	{
	public:
		ADD_VAR(::BoolProperty, bScalingToZero, 0x2)
		ADD_VAR(::BoolProperty, bRecycleScaleToZero, 0x1)
	};
}
#undef ADD_VAR
