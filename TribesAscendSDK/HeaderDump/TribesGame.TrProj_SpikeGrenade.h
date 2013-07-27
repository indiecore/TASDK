#pragma once
#include "TribesGame.TrProj_Grenade.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.h"
#include "Engine.SkelControlSingleBone.h"
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
	class TrProj_SpikeGrenade : public TrProj_Grenade
	{
	public:
		ADD_OBJECT(SoundCue, m_FractalExplosionSound, 972)
		ADD_OBJECT(ParticleSystem, m_FractalBeamTemplate, 968)
		ADD_OBJECT(ParticleSystem, m_FractalExplosionTemplate, 964)
		ADD_STRUCT(float, m_fFractalDamageRadius, 960)
		ADD_STRUCT(int, m_nFractalDamage, 956)
		ADD_STRUCT(Object::Vector, r_vFlashExplosionLocation, 944)
		ADD_STRUCT(Object::Vector, m_vAscentLocation, 932)
		ADD_STRUCT(float, m_fZFractalShotDistance, 928)
		ADD_STRUCT(float, m_fFractalShotDistance, 924)
		ADD_OBJECT(SkelControlSingleBone, m_AscendControl, 920)
		ADD_STRUCT(Object::Vector, m_CachedHitNormal, 908)
		ADD_STRUCT(float, m_fAscentHeight, 904)
		ADD_STRUCT(float, m_fAscentTime, 900)
		ADD_STRUCT(float, m_fFractalInterval, 896)
		ADD_STRUCT(float, m_fFractalTime, 892)
		ADD_STRUCT(float, m_fRemainingFractalTime, 888)
		ADD_BOOL(m_bStartedFractal, 884, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitProjectile(Object::Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.InitProjectile");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.Explode");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceivedExplosionLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.ClientReceivedExplosionLocation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsFractalActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.IsFractalActive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
		void SpawnFractalExplosionEffects(Object::Vector ShotLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.SpawnFractalExplosionEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = ShotLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndFractal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.EndFractal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnExplosionEffects(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeGrenade.SpawnExplosionEffects");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
