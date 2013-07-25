#pragma once
#include "Engine__SequenceAction.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Latent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Latent : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bAborted, 0x1)
		void AbortFor(class Actor* latentActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Latent.AbortFor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = latentActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Update(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Latent.Update");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
