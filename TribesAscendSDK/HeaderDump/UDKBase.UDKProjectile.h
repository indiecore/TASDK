#pragma once
#include "Engine.Projectile.h"
#include "Engine.Vehicle.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKProjectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKProjectile : public Projectile
	{
	public:
		ADD_OBJECT(Vehicle, InstigatorBaseVehicle)
		ADD_VAR(::FloatProperty, CustomGravityScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Buoyancy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TerminalVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LockWarningInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastLockWarningTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, InitialDir, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HomingTrackingStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseTrackingStrength, 0xFFFFFFFF)
		ADD_OBJECT(Actor, SeekTarget)
		ADD_VAR(::FloatProperty, AccelRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CheckRadius, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNotBlockedByShield, 0x8)
		ADD_VAR(::BoolProperty, bCheckProjectileLight, 0x4)
		ADD_VAR(::BoolProperty, bShuttingDown, 0x2)
		ADD_VAR(::BoolProperty, bWideCheck, 0x1)
		float GetTerminalVelocity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKProjectile.GetTerminalVelocity");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void CreateProjectileLight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKProjectile.CreateProjectileLight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
