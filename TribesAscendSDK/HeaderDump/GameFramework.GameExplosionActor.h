#pragma once
#include "GameFramework.GamePawn.h"
#include "Core.Object.h"
#include "GameFramework.GameExplosion.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.ParticleSystem.h"
#include "Engine.CameraShake.h"
#include "Engine.PlayerController.h"
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
	class GameExplosionActor : public Actor
	{
	public:
		ADD_STRUCT(Vector, ExplosionDirection, 552)
		ADD_STRUCT(float, DirectionalExplosionMinDot, 548)
		ADD_OBJECT(Controller, AttacheeController, 544)
		ADD_OBJECT(Actor, Attachee, 540)
		ADD_STRUCT(Vector, HitLocationFromPhysMaterialTrace, 528)
		ADD_OBJECT(Actor, HitActorFromPhysMaterialTrace, 524)
		ADD_OBJECT(Controller, InstigatorController, 520)
		ADD_OBJECT(GameExplosion, ExplosionTemplate, 512)
		ADD_STRUCT(float, RadialBlurMaxBlurAmount, 508)
		ADD_STRUCT(float, RadialBlurFadeTimeRemaining, 504)
		ADD_STRUCT(float, RadialBlurFadeTime, 500)
		ADD_STRUCT(float, LightInitialBrightness, 492)
		ADD_STRUCT(float, LightFadeTimeRemaining, 488)
		ADD_STRUCT(float, LightFadeTime, 484)
		ADD_BOOL(bDrawDebug, 476, 0x4)
		ADD_BOOL(bExplodeMoreThanOnce, 476, 0x2)
		ADD_BOOL(bHasExploded, 476, 0x1)
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31590);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PhysicalMaterial* GetPhysicalMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31591);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PhysicalMaterial**)params;
		}
		bool DoFullDamageToActor(class Actor* Victim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31599);
			byte params[8] = { NULL };
			*(class Actor**)params = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsBehindExplosion(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31602);
			byte params[8] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float BoxDistanceToPoint(Vector Start, Object::Box BBox)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31605);
			byte params[44] = { NULL };
			*(Vector*)params = Start;
			*(Object::Box*)&params[12] = BBox;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[40];
		}
		void DoExplosionDamage(bool bCauseDamage, bool bCauseEffects)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31609);
			byte params[8] = { NULL };
			*(bool*)params = bCauseDamage;
			*(bool*)&params[4] = bCauseEffects;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetEffectCheckRadius()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31637);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void SpecialPawnEffectsFor(class GamePawn* VictimPawn, float VictimDist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31640);
			byte params[8] = { NULL };
			*(class GamePawn**)params = VictimPawn;
			*(float*)&params[4] = VictimDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateExplosionTemplateWithPerMaterialFX(class PhysicalMaterial* PhysMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31643);
			byte params[4] = { NULL };
			*(class PhysicalMaterial**)params = PhysMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnExplosionParticleSystem(class ParticleSystem* Template)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31645);
			byte params[4] = { NULL };
			*(class ParticleSystem**)params = Template;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnExplosionDecal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31647);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnExplosionFogVolume()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31648);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Explode(class GameExplosion* NewExplosionTemplate, Vector Direction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31649);
			byte params[16] = { NULL };
			*(class GameExplosion**)params = NewExplosionTemplate;
			*(Vector*)&params[4] = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelayedExplosionDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31654);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawDebug()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31655);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31658);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoExplosionCameraEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31661);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnCameraLensEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31665);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class CameraShake* ChooseCameraShake(Vector Epicenter, class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31667);
			byte params[20] = { NULL };
			*(Vector*)params = Epicenter;
			*(class PlayerController**)&params[12] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class CameraShake**)&params[16];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
