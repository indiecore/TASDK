#pragma once
#include "UTGame.UTGib.h"
#include "Engine.ParticleSystem.h"
#include "Engine.SoundCue.h"
#include "Engine.MaterialInstanceTimeVarying.h"
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
	class UTGib_Vehicle : public UTGib
	{
	public:
		ADD_OBJECT(ScriptClass, OwningClass, 612)
		ADD_OBJECT(ParticleSystem, PS_GibExplosionEffect, 584)
		ADD_OBJECT(ParticleSystem, PS_GibTrailEffect, 588)
		ADD_STRUCT(float, TimeBeforeGibExplosionEffect, 580)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV, 608)
		ADD_STRUCT(float, BurnDuration, 604)
		ADD_STRUCT(ScriptName, BurnName, 596)
		ADD_OBJECT(SoundCue, LoopedSound, 592)
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
#undef ADD_STRUCT
#undef ADD_OBJECT
