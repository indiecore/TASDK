#pragma once
#include "Engine.Emitter.h"
#include "Engine.ParticleSystem.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.EmitterSpawnable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class EmitterSpawnable : public Emitter
	{
	public:
		ADD_OBJECT(ParticleSystem, ParticleTemplate)
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterSpawnable.SetTemplate");
			byte* params = (byte*)malloc(8);
			*(class ParticleSystem**)params = NewTemplate;
			*(bool*)(params + 4) = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterSpawnable.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
