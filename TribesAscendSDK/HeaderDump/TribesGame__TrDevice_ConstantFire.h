#pragma once
#include "TribesGame__TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_ConstantFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_ConstantFire." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_ConstantFire : public TrDevice
	{
	public:
		ADD_VAR(::NameProperty, m_PostFireState, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_FireTail)
		ADD_VAR(::FloatProperty, WeaponFireFadeTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsCurrentlyFiring, 0x4)
		ADD_VAR(::BoolProperty, m_bHasLoopingFireAnim, 0x2)
		ADD_VAR(::BoolProperty, m_bSoundLinkedWithState, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
