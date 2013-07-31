#pragma once
#include "TribesGame.TrDaDCore.h"
namespace UnrealScript
{
	class TrDaDCore_DS : public TrDaDCore
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79639);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
