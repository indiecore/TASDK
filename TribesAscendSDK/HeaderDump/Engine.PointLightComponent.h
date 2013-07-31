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
		ADD_STRUCT(Vector, Translation, 528)
		ADD_STRUCT(Object::Matrix, CachedParentToWorld, 464)
		ADD_STRUCT(float, MinShadowFalloffRadius, 448)
		ADD_STRUCT(float, ShadowFalloffExponent, 444)
		ADD_STRUCT(float, FalloffExponent, 440)
		ADD_STRUCT(float, Radius, 436)
		ADD_STRUCT(float, ShadowRadiusMultiplier, 432)
		void SetTranslation(Vector NewTranslation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14634);
			byte params[12] = { NULL };
			*(Vector*)params = NewTranslation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUpdatePropertyLightColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14636);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBrightness()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14637);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
