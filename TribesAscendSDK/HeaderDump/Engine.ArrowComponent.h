#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ArrowComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ArrowComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ArrowComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bTreatAsASprite, 0x1)
		ADD_VAR(::FloatProperty, ArrowSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, ArrowColor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
