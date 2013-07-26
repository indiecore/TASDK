#pragma once
#include "Engine.LightComponent.h"
#include "Engine.EngineTypes.LightmassPointLightSettings.h"
#include "Core.Object.Plane.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Matrix.h"
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
		ADD_STRUCT(::NonArithmeticProperty<LightmassPointLightSettings>, LightmassSettings, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Plane>, ShadowPlane, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Translation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, CachedParentToWorld, 0xFFFFFFFF)
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
