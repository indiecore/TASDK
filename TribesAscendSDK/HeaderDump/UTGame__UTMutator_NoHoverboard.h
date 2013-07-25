#pragma once
#include "UTGame__UTMutator.h"
namespace UnrealScript
{
	class UTMutator_NoHoverboard : public UTMutator
	{
	public:
		void InitMutator(ScriptArray<wchar_t> Options, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_NoHoverboard.InitMutator");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
	};
}
