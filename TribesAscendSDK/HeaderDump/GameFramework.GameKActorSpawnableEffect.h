#pragma once
#include "Engine.KActor.h"
namespace UnrealScript
{
	class GameKActorSpawnableEffect : public KActor
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31713);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31714);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartScalingDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31716);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
