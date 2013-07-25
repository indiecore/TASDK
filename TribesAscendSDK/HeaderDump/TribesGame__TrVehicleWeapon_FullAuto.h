#pragma once
#include "TribesGame__TrVehicleWeapon.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicleWeapon_FullAuto." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicleWeapon_FullAuto." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicleWeapon_FullAuto : public TrVehicleWeapon
	{
	public:
		ADD_VAR(::NameProperty, m_PostFireState, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_FireTail)
		void RefireCheckTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleWeapon_FullAuto.RefireCheckTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
