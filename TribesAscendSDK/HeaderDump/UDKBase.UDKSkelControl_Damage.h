#pragma once
#include "Engine.StaticMesh.h"
#include "Engine.SkelControlSingleBone.h"
#include "UDKBase.UDKVehicle.h"
#include "Engine.ParticleSystem.h"
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
	class UDKSkelControl_Damage : public SkelControlSingleBone
	{
	public:
		ADD_OBJECT(ParticleSystem, PS_DeathTrail, 372)
		ADD_OBJECT(ParticleSystem, PS_DeathOnBreak, 368)
		ADD_STRUCT(Vector, DeathScale, 356)
		ADD_STRUCT(Vector, DeathImpulseDir, 344)
		ADD_OBJECT(StaticMesh, DeathStaticMesh, 340)
		ADD_STRUCT(float, DeathBoneScale, 336)
		ADD_STRUCT(float, DeathPercentToActuallySpawn, 332)
		ADD_STRUCT(Vector, BreakSpeed, 320)
		ADD_STRUCT(float, OwnerVehicleMaxHealth, 316)
		ADD_STRUCT(float, BreakTimer, 312)
		ADD_STRUCT(ScriptName, BrokenBone, 304)
		ADD_OBJECT(ParticleSystem, PS_DamageTrail, 300)
		ADD_OBJECT(ParticleSystem, PS_DamageOnBreak, 296)
		ADD_STRUCT(Vector, DamageScale, 284)
		ADD_STRUCT(Vector, DefaultBreakDir, 272)
		ADD_STRUCT(float, BreakTime, 268)
		ADD_STRUCT(float, BreakThreshold, 264)
		ADD_OBJECT(StaticMesh, BreakMesh, 260)
		ADD_STRUCT(float, ActivationThreshold, 256)
		ADD_STRUCT(int, DamageMax, 252)
		ADD_STRUCT(float, DamageBoneScale, 248)
		ADD_STRUCT(float, HealthPerc, 244)
		ADD_OBJECT(UDKVehicle, OwnerVehicle, 240)
		ADD_BOOL(bOnDeathUseForSecondaryExplosion, 236, 0x80)
		ADD_BOOL(bOnDeathActive, 236, 0x40)
		ADD_BOOL(bDeathCamFollows, 236, 0x20)
		ADD_BOOL(bIsBreaking, 236, 0x10)
		ADD_BOOL(bIsBroken, 236, 0x8)
		ADD_BOOL(bControlStrFollowsHealth, 236, 0x4)
		ADD_BOOL(bOnDamageActive, 236, 0x2)
		ADD_BOOL(bInitialized, 236, 0x1)
		void BreakApart(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35371);
			byte params[16] = { NULL };
			*(Vector*)params = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakApartOnDeath(Vector PartLocation, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35374);
			byte params[16] = { NULL };
			*(Vector*)params = PartLocation;
			*(bool*)&params[12] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float RestorePart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35377);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
