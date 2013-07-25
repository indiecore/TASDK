#pragma once
#include "Engine__LightComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PointLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PointLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PointLightComponent : public LightComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightmassPointLightSettings' for the property named 'LightmassSettings'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Plane' for the property named 'ShadowPlane'!
		ADD_STRUCT(::VectorProperty, Translation, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'CachedParentToWorld'!
		ADD_VAR(::FloatProperty, MinShadowFalloffRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ShadowFalloffExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FalloffExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ShadowRadiusMultiplier, 0xFFFFFFFF)
		void SetTranslation(Vector NewTranslation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightComponent.SetTranslation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewTranslation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUpdatePropertyLightColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightComponent.OnUpdatePropertyLightColor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBrightness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightComponent.OnUpdatePropertyBrightness");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
