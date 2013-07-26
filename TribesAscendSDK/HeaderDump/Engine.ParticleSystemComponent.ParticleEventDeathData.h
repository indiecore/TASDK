#pragma once
#include "Engine.ParticleSystemComponent.ParticleEventData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleSystemComponent.ParticleEventDeathData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleEventDeathData : public ParticleEventData
	{
	public:
		ADD_VAR(::FloatProperty, ParticleTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
