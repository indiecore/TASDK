#pragma once
#include "Engine.ActorComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LightEnvironmentComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightEnvironmentComponent : public ActorComponent
	{
	public:
		ADD_VAR(::FloatProperty, DominantShadowFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTranslucencyShadowed, 0x10)
		ADD_VAR(::BoolProperty, bAllowPreShadow, 0x8)
		ADD_VAR(::BoolProperty, bAllowDynamicShadowsOnTranslucency, 0x4)
		ADD_VAR(::BoolProperty, bForceNonCompositeDynamicLights, 0x2)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		void SetEnabled(bool bNewEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightEnvironmentComponent.SetEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightEnvironmentComponent.IsEnabled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
