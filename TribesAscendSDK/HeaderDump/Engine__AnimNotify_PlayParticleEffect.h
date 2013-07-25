#pragma once
#include "Engine__AnimNotify.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNotify_PlayParticleEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNotify_PlayParticleEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotify_PlayParticleEffect : public AnimNotify
	{
	public:
		ADD_OBJECT(ParticleSystem, PSTemplate)
		ADD_VAR(::BoolProperty, bIsExtremeContent, 0x1)
		ADD_VAR(::BoolProperty, bAttach, 0x2)
		ADD_VAR(::NameProperty, SocketName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSkipIfOwnerIsHidden, 0x8)
		ADD_VAR(::BoolProperty, bPreview, 0x4)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
