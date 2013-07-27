#pragma once
#include "UDKBase.UDKUIDataProvider_MapInfo.h"
namespace UnrealScript
{
	class TrUIDataProvider_MapInfo : public UDKUIDataProvider_MapInfo
	{
	public:
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUIDataProvider_MapInfo.ShouldBeFiltered");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
