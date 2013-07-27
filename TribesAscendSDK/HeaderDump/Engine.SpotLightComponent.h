#pragma once
#include "Engine.PointLightComponent.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SpotLightComponent : public PointLightComponent
	{
	public:
		ADD_STRUCT(Object::Rotator, Rotation, 604)
		ADD_STRUCT(float, LightShaftConeAngle, 592)
		ADD_STRUCT(float, OuterConeAngle, 588)
		ADD_STRUCT(float, InnerConeAngle, 584)
		void SetRotation(Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpotLightComponent.SetRotation");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
