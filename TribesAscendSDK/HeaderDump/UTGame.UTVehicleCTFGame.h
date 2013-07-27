#pragma once
#include "UTGame.UTCTFGame.h"
namespace UnrealScript
{
	class UTVehicleCTFGame : public UTCTFGame
	{
	public:
		bool AllowMutator(ScriptString* MutatorClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49670);
			byte params[16] = { NULL };
			*(ScriptString**)params = MutatorClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
