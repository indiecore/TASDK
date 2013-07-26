#pragma once
#include "Engine.MaterialExpressionTextureSampleParameter.h"
#include "Core.Object.Pointer.h"
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
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, InstanceOverride, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
