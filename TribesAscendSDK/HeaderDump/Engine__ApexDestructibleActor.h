#pragma once
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ApexDestructibleActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ApexDestructibleActor : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bFractureMaterialOverride, 0x1)
		// Here lies the not-yet-implemented method 'SpawnFractureEmitter'
		// Here lies the not-yet-implemented method 'CacheFractureEffects'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
	};
}
#undef ADD_VAR
