#pragma once
#include "TribesGame__TrProj_StickyGrenade.h"
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
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
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'StickToTarget'
		// Here lies the not-yet-implemented method 'ProcessTouch'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'SpawnSecondaryProjectile'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
