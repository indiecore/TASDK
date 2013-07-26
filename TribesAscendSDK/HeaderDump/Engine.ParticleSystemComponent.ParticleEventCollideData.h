#pragma once
#include "Engine.ParticleSystemComponent.ParticleEventData.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleSystemComponent.ParticleEventCollideData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ParticleSystemComponent.ParticleEventCollideData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleEventCollideData : public ParticleEventData
	{
	public:
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Item, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Normal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ParticleTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
