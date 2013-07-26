#pragma once
#include "Engine.PrimitiveComponentFactory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Terrain.TerrainDecoration." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Terrain.TerrainDecoration." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TerrainDecoration
	{
	public:
		ADD_VAR(::IntProperty, RandSeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SlopeRotationBlend, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Density, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinScale, 0xFFFFFFFF)
		ADD_OBJECT(PrimitiveComponentFactory, Factory)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
