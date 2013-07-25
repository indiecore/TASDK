#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.FluidSurfaceActor.h"
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Projectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Projectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Projectile : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, NetCullDistanceSquared, 0xFFFFFFFF)
		ADD_OBJECT(Actor, ImpactedActor)
		ADD_OBJECT(Controller, InstigatorController)
		ADD_OBJECT(SoundCue, ImpactSound)
		ADD_OBJECT(SoundCue, SpawnSound)
		ADD_OBJECT(ScriptClass, MyDamageType)
		ADD_VAR(::FloatProperty, MomentumTransfer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Damage, 0xFFFFFFFF)
		ADD_OBJECT(Actor, ZeroCollider)
		ADD_VAR(::BoolProperty, bRotationFollowsVelocity, 0x8)
		ADD_VAR(::BoolProperty, bBegunPlay, 0x4)
		ADD_VAR(::BoolProperty, bBlockedByInstigator, 0x2)
		ADD_VAR(::BoolProperty, bSwitchToZeroCollision, 0x1)
		ADD_VAR(::FloatProperty, MaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Speed, 0xFFFFFFFF)
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.EncroachingOn");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
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
		void Init(Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.Init");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.GetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool CanSplash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.CanSplash");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProjectileHurtRadius(Vector HurtOrigin, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.ProjectileHurtRadius");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = HurtOrigin;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool HurtRadius(float DamageAmount, float InDamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.HurtRadius");
			byte* params = (byte*)malloc(44);
			*(float*)params = DamageAmount;
			*(float*)(params + 4) = InDamageRadius;
			*(ScriptClass**)(params + 8) = DamageType;
			*(float*)(params + 12) = Momentum;
			*(Vector*)(params + 16) = HurtOrigin;
			*(class Actor**)(params + 28) = IgnoredActor;
			*(class Controller**)(params + 32) = InstigatedByController;
			*(bool*)(params + 36) = bDoFullDamage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 40);
			free(params);
			return returnVal;
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.ProcessTouch");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.HitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.EncroachedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RandSpin(float spinRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.RandSpin");
			byte* params = (byte*)malloc(4);
			*(float*)params = spinRate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsStationary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.IsStationary");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetTimeToLocation(Vector TargetLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.GetTimeToLocation");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = TargetLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float StaticGetTimeToLocation(Vector TargetLoc, Vector StartLoc, class Controller* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.StaticGetTimeToLocation");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = TargetLoc;
			*(Vector*)(params + 12) = StartLoc;
			*(class Controller**)(params + 24) = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 28);
			free(params);
			return returnVal;
		}
		float GetRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.GetRange");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void ApplyFluidSurfaceImpact(class FluidSurfaceActor* Fluid, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Projectile.ApplyFluidSurfaceImpact");
			byte* params = (byte*)malloc(16);
			*(class FluidSurfaceActor**)params = Fluid;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
