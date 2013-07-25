#pragma once
#include "Engine__LightComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DirectionalLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DirectionalLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DirectionalLightComponent : public LightComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightmassDirectionalLightSettings' for the property named 'LightmassSettings'!
		ADD_VAR(::FloatProperty, CascadeDistributionExponent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumWholeSceneDynamicShadowCascades, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WholeSceneDynamicShadowRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TraceDistance, 0xFFFFFFFF)
		void OnUpdatePropertyLightColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DirectionalLightComponent.OnUpdatePropertyLightColor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBrightness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DirectionalLightComponent.OnUpdatePropertyBrightness");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
