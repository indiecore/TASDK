#pragma once
#include "UDKBase.UDKUIDataProvider_MapInfo.h"
namespace UnrealScript
{
	class UTUIDataProvider_MapInfo : public UDKUIDataProvider_MapInfo
	{
	public:
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38662);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool SupportedByCurrentGameMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49589);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
