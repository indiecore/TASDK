#pragma once
#include "UTGame.UTPawn.h"
#include "Engine.ParticleSystem.h"
#include "Engine.AnimSet.h"
#include "UTGame.UTWeaponAttachment.h"
#include "TribesGame.TrProj_Tracer.h"
#include "TribesGame.TrObject.h"
#include "Engine.Weapon.h"
#include "TribesGame.TrPawn.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.SoundCue.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.PhysicalMaterial.h"
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
	class TrDeviceAttachment : public UTWeaponAttachment
	{
	public:
		ADD_STRUCT(ScriptArray<class AnimSet*>, m_LightMed3pPawnAnimSets, 736)
		ADD_STRUCT(ScriptArray<class AnimSet*>, m_Heavy3pPawnAnimSets, 748)
		ADD_STRUCT(ScriptArray<TrObject::EffectFormOverwrite>, m_EffectFormOverwrite, 760)
		ADD_STRUCT(ScriptName, m_nmRidingAsPassengerFireAnimName, 772)
		ADD_STRUCT(float, m_fShowTracerDistance, 732)
		ADD_STRUCT(TrObject::EWeaponTracerType, m_TracerType, 728)
		ADD_OBJECT(ParticleSystem, m_TracerBeamTemplate, 724)
		ADD_BOOL(m_bScaleFireAnimRate, 720, 0x4)
		ADD_BOOL(m_bSpawnTracerBeams, 720, 0x2)
		ADD_BOOL(m_bSpawnTracers, 720, 0x1)
		ADD_STRUCT(ScriptName, m_nmHeavyAimProfileName, 712)
		ADD_STRUCT(ScriptName, m_nmLightMedAimProfileName, 704)
		void AttachTo(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.AttachTo");
			byte params[4] = { NULL };
			*(class UTPawn**)&params[0] = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitAnims(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.InitAnims");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachFrom(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.DetachFrom");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = MeshCpnt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPuttingDownWeapon(bool bNowPuttingDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.SetPuttingDownWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowPuttingDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldFireTracer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.ShouldFireTracer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ShouldFireTracerBeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.ShouldFireTracerBeam");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ThirdPersonFireEffects(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.ThirdPersonFireEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopThirdPersonFireEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.StopThirdPersonFireEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FirstPersonFireEffects(class Weapon* PawnWeapon, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.FirstPersonFireEffects");
			byte params[16] = { NULL };
			*(class Weapon**)&params[0] = PawnWeapon;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnTracerBeam(Object::Vector Start, Object::Vector End)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.SpawnTracerBeam");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = Start;
			*(Object::Vector*)&params[12] = End;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* SpawnTracerEffect(Object::Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.SpawnTracerEffect");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(float*)&params[12] = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[16];
		}
		class TrProj_Tracer* GetTracer(Object::Vector SpawnLocation, Object::Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.GetTracer");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = SpawnLocation;
			*(Object::Rotator*)&params[12] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[24];
		}
		void PlayReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.PlayReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayImpactEffects(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.PlayImpactEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayImpactSound(class Actor* HitActor, class SoundCue* SoundToPlay, Object::Vector FireDir, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.PlayImpactSound");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = HitActor;
			*(class SoundCue**)&params[4] = SoundToPlay;
			*(Object::Vector*)&params[8] = FireDir;
			*(Object::Vector*)&params[20] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		UDKPawn::MaterialImpactEffect GetImpactEffect(class PhysicalMaterial* HitMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.GetImpactEffect");
			byte params[52] = { NULL };
			*(class PhysicalMaterial**)&params[0] = HitMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UDKPawn::MaterialImpactEffect*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
