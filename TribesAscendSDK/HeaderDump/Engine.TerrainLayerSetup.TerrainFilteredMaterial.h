#pragma once
#include "Engine.TerrainMaterial.h"
#include "Engine.TerrainLayerSetup.FilterLimit.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TerrainLayerSetup.TerrainFilteredMaterial." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TerrainLayerSetup.TerrainFilteredMaterial." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TerrainLayerSetup.TerrainFilteredMaterial." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TerrainFilteredMaterial
	{
	public:
		ADD_OBJECT(TerrainMaterial, Material)
		ADD_VAR(::FloatProperty, Alpha, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FilterLimit>, MaxSlope, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FilterLimit>, MinSlope, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FilterLimit>, MaxHeight, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FilterLimit>, MinHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NoisePercent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NoiseScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, UseNoise, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
