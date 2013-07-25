#pragma once
#include "Engine.Actor.h"
namespace UnrealScript
{
	class StaticMeshActorBasedOnExtremeContent : public Actor
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StaticMeshActorBasedOnExtremeContent.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMaterialBasedOnExtremeContent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StaticMeshActorBasedOnExtremeContent.SetMaterialBasedOnExtremeContent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
