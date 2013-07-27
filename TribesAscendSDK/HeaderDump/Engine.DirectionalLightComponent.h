#pragma once
#include "Engine.LightComponent.h"
#include "Engine.EngineTypes.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DirectionalLightComponent : public LightComponent
	{
	public:
		ADD_STRUCT(EngineTypes::LightmassDirectionalLightSettings, LightmassSettings, 448)
		ADD_STRUCT(float, CascadeDistributionExponent, 444)
		ADD_STRUCT(int, NumWholeSceneDynamicShadowCascades, 440)
		ADD_STRUCT(float, WholeSceneDynamicShadowRadius, 436)
		ADD_STRUCT(float, TraceDistance, 432)
		void OnUpdatePropertyLightColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14489);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBrightness()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14490);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
