#pragma once
#include "TribesGame.GFxTrScene.h"
namespace UnrealScript
{
	class GFxTrScene_Header : public GFxTrScene
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63275);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
