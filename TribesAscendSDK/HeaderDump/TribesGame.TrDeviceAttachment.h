#pragma once
#include "Core.Object.Rotator.h"
#include "UTGame.UTPawn.h"
#include "Engine.ParticleSystem.h"
#include "UTGame.UTWeaponAttachment.h"
#include "Engine.Weapon.h"
#include "TribesGame.TrPawn.h"
#include "Core.Object.Vector.h"
#include "TribesGame.TrProj_Tracer.h"
#include "Engine.Actor.h"
#include "Engine.SoundCue.h"
#include "UDKBase.UDKPawn.MaterialImpactEffect.h"
#include "Engine.PhysicalMaterial.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeviceAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeviceAttachment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeviceAttachment : public UTWeaponAttachment
	{
	public:
		ADD_VAR(::NameProperty, m_nmRidingAsPassengerFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShowTracerDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_TracerType, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_TracerBeamTemplate)
		ADD_VAR(::BoolProperty, m_bScaleFireAnimRate, 0x4)
		ADD_VAR(::BoolProperty, m_bSpawnTracerBeams, 0x2)
		ADD_VAR(::BoolProperty, m_bSpawnTracers, 0x1)
		ADD_VAR(::NameProperty, m_nmHeavyAimProfileName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_nmLightMedAimProfileName, 0xFFFFFFFF)
		void AttachTo(class UTPawn* OwnerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.AttachTo");
			byte* params = (byte*)malloc(4);
			*(class UTPawn**)params = OwnerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitAnims(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.InitAnims");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachFrom(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.DetachFrom");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPuttingDownWeapon(bool bNowPuttingDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.SetPuttingDownWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowPuttingDown;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldFireTracer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.ShouldFireTracer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldFireTracerBeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.ShouldFireTracerBeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ThirdPersonFireEffects(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.ThirdPersonFireEffects");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopThirdPersonFireEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.StopThirdPersonFireEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FirstPersonFireEffects(class Weapon* PawnWeapon, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.FirstPersonFireEffects");
			byte* params = (byte*)malloc(16);
			*(class Weapon**)params = PawnWeapon;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnTracerBeam(Vector Start, Vector End)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.SpawnTracerBeam");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Start;
			*(Vector*)(params + 12) = End;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrProj_Tracer* SpawnTracerEffect(Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.SpawnTracerEffect");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitLocation;
			*(float*)(params + 12) = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProj_Tracer**)(params + 16);
			free(params);
			return returnVal;
		}
		class TrProj_Tracer* GetTracer(Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.GetTracer");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = SpawnLocation;
			*(Rotator*)(params + 12) = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProj_Tracer**)(params + 24);
			free(params);
			return returnVal;
		}
		void PlayReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.PlayReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayImpactEffects(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.PlayImpactEffects");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayImpactSound(class Actor* HitActor, class SoundCue* SoundToPlay, Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.PlayImpactSound");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = HitActor;
			*(class SoundCue**)(params + 4) = SoundToPlay;
			*(Vector*)(params + 8) = FireDir;
			*(Vector*)(params + 20) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		MaterialImpactEffect GetImpactEffect(class PhysicalMaterial* HitMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeviceAttachment.GetImpactEffect");
			byte* params = (byte*)malloc(52);
			*(class PhysicalMaterial**)params = HitMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(MaterialImpactEffect*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
