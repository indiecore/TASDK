#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.Material.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DrawCapsuleComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DrawCapsuleComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DrawCapsuleComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DrawCapsuleComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bDrawOnlyIfSelected, 0x4)
		ADD_VAR(::BoolProperty, bDrawLitCapsule, 0x2)
		ADD_VAR(::BoolProperty, bDrawWireCapsule, 0x1)
		ADD_VAR(::FloatProperty, CapsuleRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CapsuleHeight, 0xFFFFFFFF)
		ADD_OBJECT(Material, CapsuleMaterial)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'CapsuleColor'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
