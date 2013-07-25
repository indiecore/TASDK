#pragma once
#include "TribesGame.TrCTFBase.h"
namespace UnrealScript
{
	class TrCTFBase_BloodEagle : public TrCTFBase
	{
	public:
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCTFBase_BloodEagle.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
