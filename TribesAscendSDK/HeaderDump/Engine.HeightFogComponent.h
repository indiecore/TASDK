#pragma once
#include "Engine.ActorComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.HeightFogComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.HeightFogComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class HeightFogComponent : public ActorComponent
	{
	public:
		ADD_VAR(::FloatProperty, StartDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExtinctionDistance, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LightColor'!
		ADD_VAR(::FloatProperty, LightBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Density, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Height, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		void SetEnabled(bool bSetEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HeightFogComponent.SetEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bSetEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
