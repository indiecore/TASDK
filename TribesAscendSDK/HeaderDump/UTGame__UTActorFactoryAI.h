#pragma once
#include "Engine__ActorFactoryAI.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTActorFactoryAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTActorFactoryAI : public ActorFactoryAI
	{
	public:
		ADD_VAR(::BoolProperty, bUseCompartment, 0x2)
		ADD_VAR(::BoolProperty, bForceDeathmatchAI, 0x1)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTActorFactoryAI.PostCreateActor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
