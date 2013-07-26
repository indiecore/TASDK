#pragma once
#include "Engine.SpotLightComponent.h"
#include "Core.Object.Array_Mirror.h"
#include "Engine.EngineTypes.DominantShadowInfo.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DominantSpotLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DominantSpotLightComponent : public SpotLightComponent
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Array_Mirror>, DominantLightShadowMap, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<DominantShadowInfo>, DominantLightShadowInfo, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
