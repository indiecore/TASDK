#pragma once
#include "TribesGame.TrCTFBase.h"
namespace UnrealScript
{
	class TrCTFBase_DiamondSword : public TrCTFBase
	{
	public:
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase_DiamondSword.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
