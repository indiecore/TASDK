#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.Material.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DrawSphereComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DrawSphereComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DrawSphereComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DrawSphereComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bDrawOnlyIfSelected, 0x4)
		ADD_VAR(::BoolProperty, bDrawLitSphere, 0x2)
		ADD_VAR(::BoolProperty, bDrawWireSphere, 0x1)
		ADD_VAR(::IntProperty, SphereSides, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SphereRadius, 0xFFFFFFFF)
		ADD_OBJECT(Material, SphereMaterial)
		ADD_STRUCT(::NonArithmeticProperty<Color>, SphereColor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
