#pragma once
#include "Engine__SkeletalMeshActor.h"
namespace UnrealScript
{
	class SkeletalMeshActorBasedOnExtremeContent : public SkeletalMeshActor
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorBasedOnExtremeContent.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMaterialBasedOnExtremeContent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActorBasedOnExtremeContent.SetMaterialBasedOnExtremeContent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
