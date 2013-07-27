#pragma once
#include "Engine.FracturedStaticMeshActor.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.PrimitiveComponent.h"
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
	class FracturedStaticMeshPart : public FracturedStaticMeshActor
	{
	public:
		ADD_STRUCT(float, LastImpactSoundTime, 624)
		ADD_STRUCT(float, CurrentVibrationLevel, 620)
		ADD_STRUCT(Object::Vector, OldVelocity, 608)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, AsleepRBChannel, 604)
		ADD_STRUCT(float, FracPartGravScale, 600)
		ADD_STRUCT(int, PartPoolIndex, 596)
		ADD_STRUCT(float, LastSpawnTime, 592)
		ADD_BOOL(bCompositeThatExplodesOnImpact, 588, 0x4)
		ADD_BOOL(bChangeRBChannelWhenAsleep, 588, 0x2)
		ADD_BOOL(bHasBeenRecycled, 588, 0x1)
		ADD_OBJECT(FracturedStaticMeshActor, BaseFracturedMeshActor, 584)
		ADD_STRUCT(float, DestroyPartRadiusFactor, 580)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshPart.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecyclePart(bool bAddToFreePool)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshPart.RecyclePart");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAddToFreePool;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshPart.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TryToCleanUp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshPart.TryToCleanUp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshPart.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshPart.Explode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BreakOffPartsInRadius(Object::Vector Origin, float Radius, float RBStrength, bool bWantPhysChunksAndParticles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshPart.BreakOffPartsInRadius");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = Origin;
			*(float*)&params[12] = Radius;
			*(float*)&params[16] = RBStrength;
			*(bool*)&params[20] = bWantPhysChunksAndParticles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
