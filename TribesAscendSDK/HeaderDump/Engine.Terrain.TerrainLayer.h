#pragma once
#include "Core.Object.Color.h"
#include "Engine.TerrainLayerSetup.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Terrain.TerrainLayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Terrain.TerrainLayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Terrain.TerrainLayer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TerrainLayer
	{
	public:
		ADD_VAR(::IntProperty, MaxY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, WireframeColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, HighlightColor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, Hidden, 0x4)
		ADD_VAR(::BoolProperty, WireframeHighlighted, 0x2)
		ADD_VAR(::BoolProperty, Highlighted, 0x1)
		ADD_VAR(::IntProperty, AlphaMapIndex, 0xFFFFFFFF)
		ADD_OBJECT(TerrainLayerSetup, Setup)
		ADD_VAR(::StrProperty, Name, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
