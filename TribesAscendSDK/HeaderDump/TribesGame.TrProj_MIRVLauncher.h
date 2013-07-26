#pragma once
#include "TribesGame.TrProj_Grenade.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_MIRVLauncher." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_MIRVLauncher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_MIRVLauncher : public TrProj_Grenade
	{
	public:
		ADD_VAR(::IntProperty, m_nSecondaryExplosions, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_SecondaryProjectile)
		Rotator GetRandomSpread(Rotator BaseDirection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MIRVLauncher.GetRandomSpread");
			byte* params = (byte*)malloc(24);
			*(Rotator*)params = BaseDirection;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 12);
			free(params);
			return returnVal;
		}
		void SpawnSecondaryProjectile(Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MIRVLauncher.SpawnSecondaryProjectile");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MIRVLauncher.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Bounce(class Actor* Other, Vector WallNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MIRVLauncher.Bounce");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = WallNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
