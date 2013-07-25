#pragma once
#include "Engine__PointLightComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SpotLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SpotLightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SpotLightComponent : public PointLightComponent
	{
	public:
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightShaftConeAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterConeAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InnerConeAngle, 0xFFFFFFFF)
		void SetRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpotLightComponent.SetRotation");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
