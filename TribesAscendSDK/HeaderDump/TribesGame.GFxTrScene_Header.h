#pragma once
#include "TribesGame.GFxTrScene.h"
namespace UnrealScript
{
	class GFxTrScene_Header : public GFxTrScene
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_Header.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
