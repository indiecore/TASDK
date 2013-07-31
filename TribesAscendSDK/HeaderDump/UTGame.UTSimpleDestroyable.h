#pragma once
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.DynamicSMActor.h"
#include "Engine.StaticMesh.h"
#include "Engine.ParticleSystem.h"
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
	class UTSimpleDestroyable : public DynamicSMActor
	{
	public:
		ADD_STRUCT(float, TimeToRespawn, 588)
		ADD_OBJECT(StaticMesh, RespawnStaticMesh, 584)
		ADD_STRUCT(float, RespawnTime, 580)
		ADD_STRUCT(Vector, SpawnPhysMeshAngularVel, 568)
		ADD_STRUCT(Vector, SpawnPhysMeshLinearVel, 556)
		ADD_STRUCT(float, SpawnPhysMeshLifeSpan, 552)
		ADD_OBJECT(StaticMesh, SpawnPhysMesh, 548)
		ADD_OBJECT(ParticleSystem, ParticlesOnDestroy, 544)
		ADD_OBJECT(SoundCue, SoundOnDestroy, 540)
		ADD_OBJECT(StaticMesh, MeshOnDestroy, 536)
		ADD_BOOL(bDestroyed, 532, 0x8)
		ADD_BOOL(bDestroyOnVehicleTouch, 532, 0x4)
		ADD_BOOL(bDestroyOnPlayerTouch, 532, 0x2)
		ADD_BOOL(bDestroyOnDamage, 532, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49255);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GoBoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49256);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RespawnDestructible()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49258);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49259);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49267);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckRespawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49272);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
