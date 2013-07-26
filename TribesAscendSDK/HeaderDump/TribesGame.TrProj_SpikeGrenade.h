#pragma once
#include "TribesGame.TrProj_Grenade.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.Vector.h"
#include "Engine.SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_SpikeGrenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_SpikeGrenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_SpikeGrenade." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_SpikeGrenade : public TrProj_Grenade
	{
	public:
		ADD_OBJECT(SoundCue, m_FractalExplosionSound)
		ADD_OBJECT(ParticleSystem, m_FractalBeamTemplate)
		ADD_OBJECT(ParticleSystem, m_FractalExplosionTemplate)
		ADD_VAR(::FloatProperty, m_fFractalDamageRadius, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nFractalDamage, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, r_vFlashExplosionLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vAscentLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fZFractalShotDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFractalShotDistance, 0xFFFFFFFF)
		ADD_OBJECT(SkelControlSingleBone, m_AscendControl)
		ADD_STRUCT(::VectorProperty, m_CachedHitNormal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAscentHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAscentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFractalInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFractalTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingFractalTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bStartedFractal, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.InitProjectile");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Direction;
			*(ScriptClass**)(params + 12) = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceivedExplosionLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.ClientReceivedExplosionLocation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFractalActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.IsFractalActive");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void StartFractalShots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.StartFractalShots");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShootFractalShot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.ShootFractalShot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnFractalExplosionEffects(Vector ShotLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.SpawnFractalExplosionEffects");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = ShotLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndFractal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.EndFractal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnExplosionEffects(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.SpawnExplosionEffects");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
