#pragma once
#include "TribesGame__GFxTrScene.h"
namespace UnrealScript
{
	class GFxTrScene_Social : public GFxTrScene
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_Social.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
