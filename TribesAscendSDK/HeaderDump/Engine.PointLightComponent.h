#pragma once
#include "Engine.LightComponent.h"
#include "Engine.EngineTypes.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PointLightComponent : public LightComponent
	{
	public:
		ADD_STRUCT(EngineTypes::LightmassPointLightSettings, LightmassSettings, 564)
		ADD_STRUCT(Object::Plane, ShadowPlane, 544)
		ADD_STRUCT(Object::Vector, Translation, 528)
		ADD_STRUCT(Object::Matrix, CachedParentToWorld, 464)
		ADD_STRUCT(float, MinShadowFalloffRadius, 448)
		ADD_STRUCT(float, ShadowFalloffExponent, 444)
		ADD_STRUCT(float, FalloffExponent, 440)
		ADD_STRUCT(float, Radius, 436)
		ADD_STRUCT(float, ShadowRadiusMultiplier, 432)
		void SetTranslation(Object::Vector NewTranslation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PointLightComponent.SetTranslation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewTranslation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
#undef ADD_STRUCT
