#pragma once
#include "Engine__SpotLightComponent.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Array_Mirror' for the property named 'DominantLightShadowMap'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.DominantShadowInfo' for the property named 'DominantLightShadowInfo'!
	};
}
#undef ADD_STRUCT
