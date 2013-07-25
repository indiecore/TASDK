#pragma once
#include "Engine__PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LensFlareComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LensFlareComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LensFlareComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LensFlareComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, NextTraceTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ReleaseResourcesFence'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'SourceColor'!
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConeFudgeFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InnerCone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterCone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bVisibleForMobile, 0x40)
		ADD_VAR(::BoolProperty, bUsesSceneColor, 0x20)
		ADD_VAR(::BoolProperty, bHasUnlitDistortion, 0x10)
		ADD_VAR(::BoolProperty, bHasUnlitTranslucency, 0x8)
		ADD_VAR(::BoolProperty, bHasTranslucency, 0x4)
		ADD_VAR(::BoolProperty, bIsActive, 0x2)
		ADD_VAR(::BoolProperty, bAutoActivate, 0x1)
		ADD_OBJECT(LensFlare, Template)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
