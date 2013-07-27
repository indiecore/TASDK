#pragma once
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
namespace UnrealScript
{
	class UIManager : public Object
	{
	public:
		class UIManager* GetUIManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.GetUIManager");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIManager**)&params[0];
		}
		bool CanUnpauseInternalUI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.CanUnpauseInternalUI");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PauseGame(bool bDesiredPauseState, int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.PauseGame");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bDesiredPauseState;
			*(int*)&params[4] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.NotifyPlayerAdded");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			*(class LocalPlayer**)&params[4] = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIManager.NotifyPlayerRemoved");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			*(class LocalPlayer**)&params[4] = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
