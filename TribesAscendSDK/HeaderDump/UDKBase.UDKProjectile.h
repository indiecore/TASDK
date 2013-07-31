#pragma once
#include "Engine.Projectile.h"
#include "Engine.Vehicle.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
	class UDKProjectile : public Projectile
	{
	public:
		ADD_OBJECT(Vehicle, InstigatorBaseVehicle, 592)
		ADD_STRUCT(float, CustomGravityScaling, 588)
		ADD_STRUCT(float, Buoyancy, 584)
		ADD_STRUCT(float, TerminalVelocity, 580)
		ADD_STRUCT(float, LockWarningInterval, 576)
		ADD_STRUCT(float, LastLockWarningTime, 572)
		ADD_STRUCT(Vector, InitialDir, 560)
		ADD_STRUCT(float, HomingTrackingStrength, 556)
		ADD_STRUCT(float, BaseTrackingStrength, 552)
		ADD_OBJECT(Actor, SeekTarget, 548)
		ADD_STRUCT(float, AccelRate, 544)
		ADD_STRUCT(float, CheckRadius, 540)
		ADD_BOOL(bNotBlockedByShield, 536, 0x8)
		ADD_BOOL(bCheckProjectileLight, 536, 0x4)
		ADD_BOOL(bShuttingDown, 536, 0x2)
		ADD_BOOL(bWideCheck, 536, 0x1)
		float GetTerminalVelocity()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35306);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void CreateProjectileLight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35308);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
