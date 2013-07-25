#pragma once
#include "UTGame.UTCTFGame.h"
namespace UnrealScript
{
	class UTVehicleCTFGame : public UTCTFGame
	{
	public:
		bool AllowMutator(ScriptArray<wchar_t> MutatorClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleCTFGame.AllowMutator");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = MutatorClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
