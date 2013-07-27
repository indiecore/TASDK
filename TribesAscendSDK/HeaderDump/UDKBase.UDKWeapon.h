#pragma once
#include "Engine.Weapon.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKPawn.h"
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
namespace UnrealScript
{
	class UDKWeapon : public Weapon
	{
	public:
		ADD_STRUCT(ScriptArray<class Actor*>, AimingTraceIgnoredActors, 736)
		ADD_STRUCT(float, AimTraceRange, 732)
		ADD_STRUCT(byte, HitEnemy, 728)
		ADD_STRUCT(int, AmmoCount, 724)
		ADD_BOOL(bConsiderProjectileAcceleration, 720, 0x2)
		ADD_BOOL(bLeadTarget, 720, 0x1)
		bool IsAimCorrect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.IsAimCorrect");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		byte BestMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.BestMode");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnsureWeaponOverlayComponentLast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.EnsureWeaponOverlayComponentLast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPosition(class UDKPawn* Holder, float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKWeapon.SetPosition");
			byte params[8] = { NULL };
			*(class UDKPawn**)&params[0] = Holder;
			*(float*)&params[4] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
