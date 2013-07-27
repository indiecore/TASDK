#pragma once
#include "TribesGame.TrCTFBase.h"
namespace UnrealScript
{
	class TrCTFBase_BloodEagle : public TrCTFBase
	{
	public:
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase_BloodEagle.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
