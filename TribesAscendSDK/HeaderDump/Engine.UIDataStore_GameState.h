#pragma once
#include "Engine.UIDataStore.h"
namespace UnrealScript
{
	class UIDataStore_GameState : public UIDataStore
	{
	public:
		void OnRefreshDataFieldValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28557);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyGameSessionEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28559);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
