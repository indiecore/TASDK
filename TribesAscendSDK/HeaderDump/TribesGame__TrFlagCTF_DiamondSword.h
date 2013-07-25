#pragma once
#include "TribesGame__TrFlagCTF.h"
namespace UnrealScript
{
	class TrFlagCTF_DiamondSword : public TrFlagCTF
	{
	public:
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF_DiamondSword.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
