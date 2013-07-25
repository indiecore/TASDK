#pragma once
#include "TribesGame__TrDaDCore.h"
namespace UnrealScript
{
	class TrDaDCore_DS : public TrDaDCore
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCore_DS.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
