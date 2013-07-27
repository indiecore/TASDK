#pragma once
#include "TribesGame.TrDaDCore.h"
namespace UnrealScript
{
	class TrDaDCore_BE : public TrDaDCore
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79624);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
