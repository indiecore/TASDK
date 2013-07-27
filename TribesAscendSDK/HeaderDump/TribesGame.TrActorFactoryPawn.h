#pragma once
#include "UTGame.UTActorFactoryAI.h"
#include "Engine.Actor.h"
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
	class TrActorFactoryPawn : public UTActorFactoryAI
	{
	public:
		ADD_OBJECT(ScriptClass, FamilyInfo, 144)
		ADD_STRUCT(float, GroundSpeed, 140)
		ADD_STRUCT(int, NextTeam, 136)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrActorFactoryPawn.PostCreateActor");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
