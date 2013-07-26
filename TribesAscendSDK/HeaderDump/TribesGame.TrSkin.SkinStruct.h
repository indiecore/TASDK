#pragma once
#include "Engine.ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrSkin.SkinStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrSkin.SkinStruct." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SkinStruct
	{
	public:
		ADD_VAR(::IntProperty, skinId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SkinContentPath3p, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SkinContentPath1p, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, JetpackThrustTemplate)
		ADD_OBJECT(ParticleSystem, JetpackRibbonTemplate)
		ADD_OBJECT(ParticleSystem, SkiThrustTemplate)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
