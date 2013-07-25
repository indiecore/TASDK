#pragma once
#include "UTGame__UTGib.h"
#include "Engine__ParticleSystem.h"
#include "Engine__MaterialInstanceTimeVarying.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGib_Vehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTGib_Vehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTGib_Vehicle : public UTGib
	{
	public:
		ADD_OBJECT(ScriptClass, OwningClass)
		ADD_OBJECT(ParticleSystem, PS_GibExplosionEffect)
		ADD_OBJECT(ParticleSystem, PS_GibTrailEffect)
		ADD_VAR(::FloatProperty, TimeBeforeGibExplosionEffect, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV)
		ADD_VAR(::FloatProperty, BurnDuration, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BurnName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, LoopedSound)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib_Vehicle.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateGibExplosionEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib_Vehicle.ActivateGibExplosionEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
