#pragma once
#include "Engine.StaticMeshActor.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InteractiveFoliageActor : public StaticMeshActor
	{
	public:
		ADD_STRUCT(float, Mass, 568)
		ADD_STRUCT(float, MaxForce, 564)
		ADD_STRUCT(float, MaxTouchImpulse, 560)
		ADD_STRUCT(float, MaxDamageImpulse, 556)
		ADD_STRUCT(float, FoliageDamping, 552)
		ADD_STRUCT(float, FoliageStiffnessQuadratic, 548)
		ADD_STRUCT(float, FoliageStiffness, 544)
		ADD_STRUCT(float, FoliageTouchImpulseScale, 540)
		ADD_STRUCT(float, FoliageDamageImpulseScale, 536)
		ADD_STRUCT(Vector, FoliagePosition, 524)
		ADD_STRUCT(Vector, FoliageForce, 512)
		ADD_STRUCT(Vector, FoliageVelocity, 500)
		ADD_STRUCT(Vector, TouchingActorEntryPosition, 488)
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18334);
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
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18342);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
