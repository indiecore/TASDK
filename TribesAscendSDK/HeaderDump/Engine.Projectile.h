#pragma once
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.FluidSurfaceActor.h"
#include "Engine.SoundCue.h"
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
	class Projectile : public Actor
	{
	public:
		ADD_STRUCT(float, NetCullDistanceSquared, 528)
		ADD_OBJECT(Actor, ImpactedActor, 524)
		ADD_OBJECT(Controller, InstigatorController, 520)
		ADD_OBJECT(SoundCue, ImpactSound, 516)
		ADD_OBJECT(SoundCue, SpawnSound, 512)
		ADD_OBJECT(ScriptClass, MyDamageType, 508)
		ADD_STRUCT(float, MomentumTransfer, 504)
		ADD_STRUCT(float, DamageRadius, 500)
		ADD_STRUCT(float, Damage, 496)
		ADD_OBJECT(Actor, ZeroCollider, 488)
		ADD_BOOL(bRotationFollowsVelocity, 484, 0x8)
		ADD_BOOL(bBegunPlay, 484, 0x4)
		ADD_BOOL(bBlockedByInstigator, 484, 0x2)
		ADD_BOOL(bSwitchToZeroCollision, 484, 0x1)
		ADD_STRUCT(float, MaxSpeed, 480)
		ADD_STRUCT(float, Speed, 476)
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24859);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24862);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24863);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init(Vector Direction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24864);
			byte params[12] = { NULL };
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24866);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		bool CanSplash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24868);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24870);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProjectileHurtRadius(Vector HurtOrigin, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24871);
			byte params[28] = { NULL };
			*(Vector*)params = HurtOrigin;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool HurtRadius(float DamageAmount, float InDamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24879);
			byte params[44] = { NULL };
			*(float*)params = DamageAmount;
			*(float*)&params[4] = InDamageRadius;
			*(ScriptClass**)&params[8] = DamageType;
			*(float*)&params[12] = Momentum;
			*(Vector*)&params[16] = HurtOrigin;
			*(class Actor**)&params[28] = IgnoredActor;
			*(class Controller**)&params[32] = InstigatedByController;
			*(bool*)&params[36] = bDoFullDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24891);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24896);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24900);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24906);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24908);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RandSpin(float spinRate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24911);
			byte params[4] = { NULL };
			*(float*)params = spinRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsStationary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24913);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24915);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetTimeToLocation(Vector TargetLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24917);
			byte params[16] = { NULL };
			*(Vector*)params = TargetLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float StaticGetTimeToLocation(Vector TargetLoc, Vector StartLoc, class Controller* RequestedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24920);
			byte params[32] = { NULL };
			*(Vector*)params = TargetLoc;
			*(Vector*)&params[12] = StartLoc;
			*(class Controller**)&params[24] = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[28];
		}
		float GetRange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24925);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void ApplyFluidSurfaceImpact(class FluidSurfaceActor* Fluid, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24927);
			byte params[16] = { NULL };
			*(class FluidSurfaceActor**)params = Fluid;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
