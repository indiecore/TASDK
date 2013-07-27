#pragma once
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "Engine.MaterialInterface.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TerrainMaterial : public Object
	{
	public:
		enum ETerrainMappingType : byte
		{
			TMT_Auto = 0,
			TMT_XY = 1,
			TMT_XZ = 2,
			TMT_YZ = 3,
			TMT_MAX = 4,
		};
		ADD_STRUCT(float, DisplacementScale, 156)
		ADD_OBJECT(Texture2D, DisplacementMap, 152)
		ADD_OBJECT(MaterialInterface, Material, 148)
		ADD_STRUCT(float, MappingPanV, 144)
		ADD_STRUCT(float, MappingPanU, 140)
		ADD_STRUCT(float, MappingRotation, 136)
		ADD_STRUCT(float, MappingScale, 132)
		ADD_STRUCT(TerrainMaterial::ETerrainMappingType, MappingType, 128)
		ADD_STRUCT(Object::Matrix, LocalToMapping, 64)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
