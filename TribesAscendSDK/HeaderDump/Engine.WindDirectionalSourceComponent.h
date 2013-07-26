#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.WindDirectionalSourceComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.WindDirectionalSourceComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WindDirectionalSourceComponent : public ActorComponent
	{
	public:
		ADD_VAR(::FloatProperty, Speed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Frequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Phase, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Strength, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, SceneProxy, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
