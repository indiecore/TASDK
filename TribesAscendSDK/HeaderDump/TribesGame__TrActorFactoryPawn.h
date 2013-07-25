#pragma once
#include "UTGame__UTActorFactoryAI.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrActorFactoryPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrActorFactoryPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrActorFactoryPawn : public UTActorFactoryAI
	{
	public:
		ADD_OBJECT(ScriptClass, FamilyInfo)
		ADD_VAR(::FloatProperty, GroundSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NextTeam, 0xFFFFFFFF)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrActorFactoryPawn.PostCreateActor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
