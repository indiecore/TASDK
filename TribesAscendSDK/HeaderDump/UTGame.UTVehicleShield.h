#pragma once
#include "UDKBase.UDKWeaponShield.h"
#include "Engine.SoundCue.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class UTVehicleShield : public UDKWeaponShield
	{
	public:
		ADD_BOOL(bFullyActive, 500, 0x1)
		ADD_STRUCT(float, ShieldActivatedTime, 496)
		ADD_OBJECT(SoundCue, DeactivatedSound, 484)
		ADD_OBJECT(SoundCue, ActivatedSound, 480)
		void SetActive(bool bNowActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49803);
			byte params[4] = { NULL };
			*(bool*)params = bNowActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShieldFullyOnline()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49805);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49806);
			byte params[68] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
