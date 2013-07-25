#pragma once
#include "Engine__ActorFactoryVehicle.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTActorFactoryVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTActorFactoryVehicle : public ActorFactoryVehicle
	{
	public:
		ADD_VAR(::ByteProperty, TeamNum, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bKeyVehicle, 0x2)
		ADD_VAR(::BoolProperty, bTeamLocked, 0x1)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTActorFactoryVehicle.PostCreateActor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
