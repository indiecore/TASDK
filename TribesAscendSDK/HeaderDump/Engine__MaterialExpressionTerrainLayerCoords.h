#pragma once
#include "Engine__MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionTerrainLayerCoords." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTerrainLayerCoords : public MaterialExpression
	{
	public:
		ADD_VAR(::FloatProperty, MappingPanV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MappingPanU, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MappingRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MappingScale, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MappingType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
