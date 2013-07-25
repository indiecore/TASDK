#pragma once
#include "TribesGame.TrProj_StickyGrenade.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_SpikeLauncher." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_SpikeLauncher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_SpikeLauncher : public TrProj_StickyGrenade
	{
	public:
		ADD_OBJECT(ParticleSystem, ProjExplosionTemplateAir)
		ADD_VAR(::BoolProperty, m_bInAirHit, 0x1)
		ADD_OBJECT(ScriptClass, m_ThirdProjectile)
		ADD_OBJECT(ScriptClass, m_SecondProjectile)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeLauncher.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StickToTarget(class Actor* Target, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeLauncher.StickToTarget");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Target;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeLauncher.ProcessTouch");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeLauncher.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnSecondaryProjectile(Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpikeLauncher.SpawnSecondaryProjectile");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
