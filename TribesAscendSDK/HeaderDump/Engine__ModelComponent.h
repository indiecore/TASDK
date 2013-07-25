#pragma once
#include "Engine__PrimitiveComponent.h"
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ModelComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ModelComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ModelComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::IntProperty, ComponentIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ZoneIndex, 0xFFFFFFFF)
		ADD_OBJECT(Object, Model)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
