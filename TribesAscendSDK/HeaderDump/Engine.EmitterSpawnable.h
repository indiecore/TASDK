#pragma once
#include "Engine.Emitter.h"
#include "Engine.ParticleSystem.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class EmitterSpawnable : public Emitter
	{
	public:
		ADD_OBJECT(ParticleSystem, ParticleTemplate, 488)
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterSpawnable.SetTemplate");
			byte params[8] = { NULL };
			*(class ParticleSystem**)&params[0] = NewTemplate;
			*(bool*)&params[4] = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterSpawnable.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
