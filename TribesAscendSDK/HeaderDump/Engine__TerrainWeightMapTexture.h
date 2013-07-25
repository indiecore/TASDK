#pragma once
#include "Engine__Texture2D.h"
#include "Engine__Terrain.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.TerrainWeightMapTexture." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TerrainWeightMapTexture : public Texture2D
	{
	public:
		ADD_OBJECT(Terrain, ParentTerrain)
	};
}
#undef ADD_OBJECT
