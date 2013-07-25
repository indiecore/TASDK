#pragma once
#include "Engine__SeqAct_SetParticleSysParam.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "Engine__SeqAct_ParticleEventGenerator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Emitter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Emitter : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bCurrentlyActive, 0x4)
		ADD_VAR(::BoolProperty, bPostUpdateTickGroup, 0x2)
		ADD_VAR(::BoolProperty, bDestroyOnSystemFinish, 0x1)
		// Here lies the not-yet-implemented method 'SetTemplate'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'OnParticleSystemFinished'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'OnParticleEventGenerator'
		// Here lies the not-yet-implemented method 'ShutDown'
		// Here lies the not-yet-implemented method 'SetFloatParameter'
		// Here lies the not-yet-implemented method 'SetVectorParameter'
		// Here lies the not-yet-implemented method 'SetColorParameter'
		// Here lies the not-yet-implemented method 'SetExtColorParameter'
		// Here lies the not-yet-implemented method 'SetActorParameter'
		// Here lies the not-yet-implemented method 'OnSetParticleSysParam'
		// Here lies the not-yet-implemented method 'ShouldSaveForCheckpoint'
		// Here lies the not-yet-implemented method 'CreateCheckpointRecord'
		// Here lies the not-yet-implemented method 'ApplyCheckpointRecord'
		// Here lies the not-yet-implemented method 'HideSelf'
	};
}
#undef ADD_VAR
