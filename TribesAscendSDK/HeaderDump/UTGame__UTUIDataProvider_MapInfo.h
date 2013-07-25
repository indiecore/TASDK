#pragma once
#include "UDKBase__UDKUIDataProvider_MapInfo.h"
namespace UnrealScript
{
	class UTUIDataProvider_MapInfo : public UDKUIDataProvider_MapInfo
	{
	public:
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTUIDataProvider_MapInfo.ShouldBeFiltered");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SupportedByCurrentGameMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTUIDataProvider_MapInfo.SupportedByCurrentGameMode");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
