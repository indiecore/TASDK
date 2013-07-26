#pragma once
#include "Core.Object.Matrix.h"
#include "Core.Object.Box.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EngineTypes.DominantShadowInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty EngineTypes.DominantShadowInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DominantShadowInfo
	{
	public:
		ADD_VAR(::IntProperty, ShadowMapSizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ShadowMapSizeX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Box>, LightSpaceImportanceBounds, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, LightToWorld, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, WorldToLight, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
