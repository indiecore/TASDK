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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28358);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetMaxTotalGamerScore()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28360);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void PopulateAchievementIcons()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28362);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetAchievementIconPathName(int AchievementId, bool bReturnLockedIcon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28363);
			byte params[20] = { NULL };
			*(int*)params = AchievementId;
			*(bool*)&params[4] = bReturnLockedIcon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		void GetAchievementDetails(int AchievementId, OnlineSubsystem::AchievementDetails& OutAchievementDetails)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28367);
			byte params[56] = { NULL };
			*(int*)params = AchievementId;
			*(OnlineSubsystem::AchievementDetails*)&params[4] = OutAchievementDetails;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutAchievementDetails = *(OnlineSubsystem::AchievementDetails*)&params[4];
		}
		void OnPlayerAchievementsChanged(int TitleId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28371);
			byte params[4] = { NULL };
			*(int*)params = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayerAchievementUnlocked(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28375);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28377);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28380);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28382);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateAchievements()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28384);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
