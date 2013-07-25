#pragma once
#include "TribesGame__GFxTrScene.h"
namespace UnrealScript
{
	class GFxTrScene_Profile : public GFxTrScene
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_Profile.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
