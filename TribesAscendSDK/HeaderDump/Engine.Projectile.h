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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.EncroachingOn");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init(Object::Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.Init");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.GetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		bool CanSplash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.CanSplash");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProjectileHurtRadius(Object::Vector HurtOrigin, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.ProjectileHurtRadius");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = HurtOrigin;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool HurtRadius(float DamageAmount, float InDamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.HurtRadius");
			byte params[44] = { NULL };
			*(float*)&params[0] = DamageAmount;
			*(float*)&params[4] = InDamageRadius;
			*(ScriptClass**)&params[8] = DamageType;
			*(float*)&params[12] = Momentum;
			*(Object::Vector*)&params[16] = HurtOrigin;
			*(class Actor**)&params[28] = IgnoredActor;
			*(class Controller**)&params[32] = InstigatedByController;
			*(bool*)&params[36] = bDoFullDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.ProcessTouch");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HitWall(Object::Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.HitWall");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.EncroachedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.Explode");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RandSpin(float spinRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.RandSpin");
			byte params[4] = { NULL };
			*(float*)&params[0] = spinRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsStationary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.IsStationary");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetTimeToLocation(Object::Vector TargetLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.GetTimeToLocation");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = TargetLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float StaticGetTimeToLocation(Object::Vector TargetLoc, Object::Vector StartLoc, class Controller* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.StaticGetTimeToLocation");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = TargetLoc;
			*(Object::Vector*)&params[12] = StartLoc;
			*(class Controller**)&params[24] = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[28];
		}
		float GetRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.GetRange");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void ApplyFluidSurfaceImpact(class FluidSurfaceActor* Fluid, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.ApplyFluidSurfaceImpact");
			byte params[16] = { NULL };
			*(class FluidSurfaceActor**)&params[0] = Fluid;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
