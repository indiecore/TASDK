#pragma once
#include "UDKBase.UDKUIDataProvider_MapInfo.h"
namespace UnrealScript
{
	class UTUIDataProvider_MapInfo : public UDKUIDataProvider_MapInfo
	{
	public:
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTUIDataProvider_MapInfo.ShouldBeFiltered");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SupportedByCurrentGameMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTUIDataProvider_MapInfo.SupportedByCurrentGameMode");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
