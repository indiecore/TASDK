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
		ADD_STRUCT(Vector, OldVelocity, 608)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16603);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecyclePart(bool bAddToFreePool)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16604);
			byte params[4] = { NULL };
			*(bool*)params = bAddToFreePool;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16606);
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
		void TryToCleanUp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16614);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16615);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16617);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BreakOffPartsInRadius(Vector Origin, float Radius, float RBStrength, bool bWantPhysChunksAndParticles)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16618);
			byte params[24] = { NULL };
			*(Vector*)params = Origin;
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
