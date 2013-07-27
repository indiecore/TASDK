#pragma once
#include "Engine.UIDataStore.h"
namespace UnrealScript
{
	class UIDataStore_GameState : public UIDataStore
	{
	public:
		void OnRefreshDataFieldValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_GameState.OnRefreshDataFieldValue");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_GameState.NotifyGameSessionEnded");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
