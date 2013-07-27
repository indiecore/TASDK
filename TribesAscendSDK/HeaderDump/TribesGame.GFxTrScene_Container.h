#pragma once
#include "TribesGame.GFxTrScene.h"
namespace UnrealScript
{
	class GFxTrScene_Container : public GFxTrScene
	{
	public:
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63263);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
