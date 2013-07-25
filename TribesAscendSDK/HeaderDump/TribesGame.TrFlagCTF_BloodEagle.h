#pragma once
#include "TribesGame.TrFlagCTF.h"
namespace UnrealScript
{
	class TrFlagCTF_BloodEagle : public TrFlagCTF
	{
	public:
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF_BloodEagle.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
