#pragma once
#include "Engine.UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine.OnlineSubsystem.h"
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_PlayerAchievements : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem::AchievementDetails>, Achievements, 96)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 92)
		int GetTotalGamerScore()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.GetTotalGamerScore");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetMaxTotalGamerScore()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.GetMaxTotalGamerScore");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void PopulateAchievementIcons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.PopulateAchievementIcons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetAchievementIconPathName(int AchievementId, bool bReturnLockedIcon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.GetAchievementIconPathName");
			byte params[20] = { NULL };
			*(int*)&params[0] = AchievementId;
			*(bool*)&params[4] = bReturnLockedIcon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		void GetAchievementDetails(int AchievementId, OnlineSubsystem::AchievementDetails& OutAchievementDetails)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.GetAchievementDetails");
			byte params[56] = { NULL };
			*(int*)&params[0] = AchievementId;
			*(OnlineSubsystem::AchievementDetails*)&params[4] = OutAchievementDetails;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutAchievementDetails = *(OnlineSubsystem::AchievementDetails*)&params[4];
		}
		void OnPlayerAchievementsChanged(int TitleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnPlayerAchievementsChanged");
			byte params[4] = { NULL };
			*(int*)&params[0] = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayerAchievementUnlocked(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnPlayerAchievementUnlocked");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnRegister");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnUnregister");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnLoginChange");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateAchievements()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.UpdateAchievements");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
