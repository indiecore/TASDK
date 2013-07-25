#pragma once
#include "Engine__ParticleSystemComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKParticleSystemComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKParticleSystemComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKParticleSystemComponent : public ParticleSystemComponent
	{
	public:
		ADD_STRUCT(::VectorProperty, SavedScale3D, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bHasSavedScale3D, 0x1)
		ADD_VAR(::FloatProperty, FOV, 0xFFFFFFFF)
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKParticleSystemComponent.SetFOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
