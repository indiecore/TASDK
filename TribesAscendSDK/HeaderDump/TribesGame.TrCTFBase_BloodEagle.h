#pragma once
#include "TribesGame.TrCTFBase.h"
namespace UnrealScript
{
	class TrCTFBase_BloodEagle : public TrCTFBase
	{
	public:
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78277);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
