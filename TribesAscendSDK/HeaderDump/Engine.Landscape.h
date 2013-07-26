#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.Info.h"
#include "Engine.EngineTypes.LightmassPrimitiveSettings.h"
#include "Engine.Material.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Landscape." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Landscape." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Landscape." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Landscape : public Info
	{
	public:
		ADD_VAR(::IntProperty, NumSubsections, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SubsectionSizeQuads, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ComponentSizeQuads, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, DataInterface, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StreamingDistanceMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StaticLightingResolution, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LightmassPrimitiveSettings>, LightmassSettings, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLODLevel, 0xFFFFFFFF)
		ADD_OBJECT(Material, LandscapeMaterial)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
