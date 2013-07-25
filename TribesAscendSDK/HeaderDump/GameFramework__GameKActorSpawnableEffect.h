#pragma once
#include "Engine__KActor.h"
namespace UnrealScript
{
	class GameKActorSpawnableEffect : public KActor
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameKActorSpawnableEffect.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameKActorSpawnableEffect.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartScalingDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameKActorSpawnableEffect.StartScalingDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
