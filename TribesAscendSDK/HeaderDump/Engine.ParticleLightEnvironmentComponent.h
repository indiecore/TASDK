#pragma once
#include "Engine.DynamicLightEnvironmentComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleLightEnvironmentComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleLightEnvironmentComponent : public DynamicLightEnvironmentComponent
	{
	public:
		ADD_VAR(::BoolProperty, bAllowDLESharing, 0x1)
		ADD_VAR(::IntProperty, ReferenceCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
