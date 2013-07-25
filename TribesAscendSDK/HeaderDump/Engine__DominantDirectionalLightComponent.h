#pragma once
#include "Engine__DirectionalLightComponent.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DominantDirectionalLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DominantDirectionalLightComponent : public DirectionalLightComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Array_Mirror' for the property named 'DominantLightShadowMap'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.DominantShadowInfo' for the property named 'DominantLightShadowInfo'!
	};
}
#undef ADD_STRUCT
