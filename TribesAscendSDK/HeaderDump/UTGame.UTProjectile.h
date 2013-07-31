#pragma once
#include "UDKBase.UDKProjectile.h"
#include "Engine.MaterialInterface.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.SoundCue.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
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
	class UTProjectile : public UDKProjectile
	{
	public:
		ADD_STRUCT(float, GlobalCheckRadiusTweak, 656)
		ADD_STRUCT(float, TossZ, 652)
		ADD_STRUCT(float, MaxExplosionLightDistance, 672)
		ADD_OBJECT(ScriptClass, ExplosionLightClass, 668)
		ADD_OBJECT(ScriptClass, ProjectileLightClass, 660)
		ADD_STRUCT(float, MaxEffectDistance, 648)
		ADD_STRUCT(ScriptName, DecalDissolveParamName, 640)
		ADD_STRUCT(float, DurationOfDecal, 636)
		ADD_STRUCT(float, DecalHeight, 632)
		ADD_STRUCT(float, DecalWidth, 628)
		ADD_OBJECT(MaterialInterface, ExplosionDecal, 624)
		ADD_OBJECT(ParticleSystem, ProjExplosionTemplate, 620)
		ADD_OBJECT(ParticleSystem, ProjFlightTemplate, 616)
		ADD_OBJECT(SoundCue, ExplosionSound, 604)
		ADD_OBJECT(SoundCue, AmbientSound, 600)
		ADD_BOOL(bAttachExplosionToVehicles, 596, 0x40)
		ADD_BOOL(bWaitForEffects, 596, 0x20)
		ADD_BOOL(bSuppressExplosionFX, 596, 0x10)
		ADD_BOOL(bAdvanceExplosionEffect, 596, 0x8)
		ADD_BOOL(m_bDestroyProjEffects, 596, 0x4)
		ADD_BOOL(bImportantAmbientSound, 596, 0x2)
		ADD_BOOL(bSuppressSounds, 596, 0x1)
		void CreateProjectileLight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48899);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48900);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSplash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48903);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48905);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48907);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48908);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Init(Vector Direction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48909);
			byte params[12] = { NULL };
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48911);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48915);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48918);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetExplosionEffectParameters(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* ProjExplosion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48919);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = ProjExplosion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundCue* GetExplosionSound(class PhysicalMaterial* HitMaterial, class Actor* HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48921);
			byte params[12] = { NULL };
			*(class PhysicalMaterial**)params = HitMaterial;
			*(class Actor**)&params[4] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[8];
		}
		void SpawnExplosionEffects(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48925);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldSpawnExplosionLight(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48941);
			byte params[28] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48947);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TornOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48950);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideProjectile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48951);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48953);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MyOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48954);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48959);
			byte params[36] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		class Actor* GetHomingTarget(class UTProjectile* Seeker, class Controller* InstigatedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48965);
			byte params[12] = { NULL };
			*(class UTProjectile**)params = Seeker;
			*(class Controller**)&params[4] = InstigatedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[8];
		}
		class Pawn* GetPawnOwner()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48969);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pawn**)params;
		}
		float CalculateTravelTime(float Dist, float MoveSpeed, float MaxMoveSpeed, float AccelMag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48971);
			byte params[20] = { NULL };
			*(float*)params = Dist;
			*(float*)&params[4] = MoveSpeed;
			*(float*)&params[8] = MaxMoveSpeed;
			*(float*)&params[12] = AccelMag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		float StaticGetTimeToLocation(Vector TargetLoc, Vector StartLoc, class Controller* RequestedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48980);
			byte params[32] = { NULL };
			*(Vector*)params = TargetLoc;
			*(Vector*)&params[12] = StartLoc;
			*(class Controller**)&params[24] = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[28];
		}
		float GetTimeToLocation(Vector TargetLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48985);
			byte params[16] = { NULL };
			*(Vector*)params = TargetLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetRange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48988);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
