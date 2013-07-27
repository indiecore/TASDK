#pragma once
#include "TribesGame.TrVehicleWeapon.h"
#include "Engine.SoundCue.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicleWeapon_FullAuto : public TrVehicleWeapon
	{
	public:
		ADD_STRUCT(ScriptArray<class SoundCue*>, WeaponFireFullAutoSnd, 1780)
		ADD_STRUCT(ScriptName, m_PostFireState, 1796)
		ADD_OBJECT(SoundCue, m_FireTail, 1792)
		void RefireCheckTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115283);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
