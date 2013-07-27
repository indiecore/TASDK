#pragma once
#include "Engine.SpotLightComponent.h"
#include "Core.Object.h"
#include "Engine.EngineTypes.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DominantSpotLightComponent : public SpotLightComponent
	{
	public:
		ADD_STRUCT(Object::Array_Mirror, DominantLightShadowMap, 800)
		ADD_STRUCT(EngineTypes::DominantShadowInfo, DominantLightShadowInfo, 624)
	};
}
#undef ADD_STRUCT
