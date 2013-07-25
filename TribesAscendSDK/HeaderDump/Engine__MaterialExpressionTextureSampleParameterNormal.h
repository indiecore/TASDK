#pragma once
#include "Engine__MaterialExpressionTextureSampleParameter.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionTextureSampleParameterNormal." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTextureSampleParameterNormal : public MaterialExpressionTextureSampleParameter
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'InstanceOverride'!
	};
}
#undef ADD_STRUCT
