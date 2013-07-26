#pragma once
#include "Engine.StaticMeshActor.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.Actor.TraceHitInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InteractiveFoliageActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InteractiveFoliageActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InteractiveFoliageActor : public StaticMeshActor
	{
	public:
		ADD_VAR(::FloatProperty, Mass, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTouchImpulse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDamageImpulse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageStiffnessQuadratic, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageTouchImpulseScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageDamageImpulseScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FoliagePosition, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FoliageForce, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FoliageVelocity, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TouchingActorEntryPosition, 0xFFFFFFFF)
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InteractiveFoliageActor.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InteractiveFoliageActor.Touch");
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
