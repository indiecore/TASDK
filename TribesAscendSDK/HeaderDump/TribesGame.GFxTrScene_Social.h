#pragma once
#include "TribesGame.GFxTrScene.h"
namespace UnrealScript
{
	class GFxTrScene_Social : public GFxTrScene
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63774);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
