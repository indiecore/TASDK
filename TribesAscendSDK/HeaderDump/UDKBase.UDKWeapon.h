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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35784);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		byte BestMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35805);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36274);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnsureWeaponOverlayComponentLast()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36275);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPosition(class UDKPawn* Holder, float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36276);
			byte params[8] = { NULL };
			*(class UDKPawn**)params = Holder;
			*(float*)&params[4] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
