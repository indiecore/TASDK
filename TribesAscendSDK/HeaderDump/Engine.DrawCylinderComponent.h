#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.Material.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DrawCylinderComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DrawCylinderComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DrawCylinderComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DrawCylinderComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bDrawOnlyIfSelected, 0x4)
		ADD_VAR(::BoolProperty, bDrawLitCylinder, 0x2)
		ADD_VAR(::BoolProperty, bDrawWireCylinder, 0x1)
		ADD_VAR(::IntProperty, CylinderSides, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CylinderHeightOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CylinderHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CylinderTopRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CylinderRadius, 0xFFFFFFFF)
		ADD_OBJECT(Material, CylinderMaterial)
		ADD_STRUCT(::NonArithmeticProperty<Color>, CylinderColor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
