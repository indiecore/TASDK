#pragma once
#include "UTGame.UTCTFGame.h"
namespace UnrealScript
{
	class UTVehicleCTFGame : public UTCTFGame
	{
	public:
		bool AllowMutator(ScriptString* MutatorClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleCTFGame.AllowMutator");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = MutatorClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
