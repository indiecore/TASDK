#pragma once
#include "Engine__SoundCue.h"
#include "Core__Object.h"
#include "Engine__Material.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEffectForm." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrEffectForm." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrEffectForm : public Object
	{
	public:
		ADD_VAR(::BoolProperty, m_bIsManaged, 0x2)
		ADD_OBJECT(Material, m_BodyMat)
		ADD_VAR(::ByteProperty, m_ePriority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bApplied, 0x1)
		ADD_OBJECT(SoundCue, m_SoundCue)
		ADD_OBJECT(ParticleSystem, m_PSC)
		ADD_VAR(::ByteProperty, m_eMatType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBodyMatFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBodyMatFadeInTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetOverwriteMat'
		// Here lies the not-yet-implemented method 'GetMatApplyToPawn'
		// Here lies the not-yet-implemented method 'GetMatApplyToWeapon'
		// Here lies the not-yet-implemented method 'GetMatApplyToAttachment'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
