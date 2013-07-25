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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
