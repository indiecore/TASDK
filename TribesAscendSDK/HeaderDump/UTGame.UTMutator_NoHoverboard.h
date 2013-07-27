#pragma once
#include "UTGame.UTMutator.h"
namespace UnrealScript
{
	class UTMutator_NoHoverboard : public UTMutator
	{
	public:
		void InitMutator(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_NoHoverboard.InitMutator");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
	};
}
