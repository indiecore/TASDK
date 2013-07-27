#pragma once
#include "UDKBase.UDKUIDataProvider_MapInfo.h"
namespace UnrealScript
{
	class TrUIDataProvider_MapInfo : public UDKUIDataProvider_MapInfo
	{
	public:
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113383);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
