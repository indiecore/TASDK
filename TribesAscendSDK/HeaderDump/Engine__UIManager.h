#pragma once
#include "Core__Object.h"
#include "Engine__LocalPlayer.h"
namespace UnrealScript
{
	class UIManager : public Object
	{
	public:
		class UIManager* GetUIManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.GetUIManager");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIManager**)params;
			free(params);
			return returnVal;
		}
		bool CanUnpauseInternalUI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.CanUnpauseInternalUI");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PauseGame(bool bDesiredPauseState, int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.PauseGame");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bDesiredPauseState;
			*(int*)(params + 4) = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.NotifyPlayerAdded");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.NotifyPlayerRemoved");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
