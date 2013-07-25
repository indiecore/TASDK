#pragma once
#include "TribesGame__GFxTrScene.h"
namespace UnrealScript
{
	class GFxTrScene_Container : public GFxTrScene
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_Container.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
