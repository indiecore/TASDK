#pragma once
#include "Engine.ParticleSystemComponent.ParticleEventData.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleSystemComponent.ParticleEventKismetData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ParticleSystemComponent.ParticleEventKismetData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleEventKismetData : public ParticleEventData
	{
	public:
		ADD_STRUCT(::VectorProperty, Normal, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, UsePSysCompLocation, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
