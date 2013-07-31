#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTerrainLayerCoords : public MaterialExpression
	{
	public:
		enum ETerrainCoordMappingType : byte
		{
			TCMT_Auto = 0,
			TCMT_XY = 1,
			TCMT_XZ = 2,
			TCMT_YZ = 3,
			TCMT_MAX = 4,
		};
		ADD_STRUCT(float, MappingPanV, 124)
		ADD_STRUCT(float, MappingPanU, 120)
		ADD_STRUCT(float, MappingRotation, 116)
		ADD_STRUCT(float, MappingScale, 112)
		ADD_STRUCT(MaterialExpressionTerrainLayerCoords::ETerrainCoordMappingType, MappingType, 108)
	};
}
#undef ADD_STRUCT
