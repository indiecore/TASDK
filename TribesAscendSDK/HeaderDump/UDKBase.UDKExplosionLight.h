#pragma once
#include "Engine.PointLightComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKExplosionLight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKExplosionLight : public PointLightComponent
	{
	public:
		ADD_VAR(::IntProperty, TimeShiftIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Lifetime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighDetailFrameTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInitialized, 0x2)
		ADD_VAR(::BoolProperty, bCheckFrameRate, 0x1)
		void OnLightFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Light)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKExplosionLight.OnLightFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Light;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetLight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKExplosionLight.ResetLight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
