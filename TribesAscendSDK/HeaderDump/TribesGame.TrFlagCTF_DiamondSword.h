#pragma once
#include "TribesGame.TrFlagCTF.h"
namespace UnrealScript
{
	class TrFlagCTF_DiamondSword : public TrFlagCTF
	{
	public:
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF_DiamondSword.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
