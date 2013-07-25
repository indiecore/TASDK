#pragma once
#include "Engine__UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine__LocalPlayer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_PlayerAchievements." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_PlayerAchievements : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		int GetTotalGamerScore()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.GetTotalGamerScore");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetMaxTotalGamerScore()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.GetMaxTotalGamerScore");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void PopulateAchievementIcons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.PopulateAchievementIcons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetAchievementIconPathName(int AchievementId, bool bReturnLockedIcon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.GetAchievementIconPathName");
			byte* params = (byte*)malloc(20);
			*(int*)params = AchievementId;
			*(bool*)(params + 4) = bReturnLockedIcon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		void GetAchievementDetails(int AchievementId, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.AchievementDetails'!
void*& OutAchievementDetails)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.GetAchievementDetails");
			byte* params = (byte*)malloc(56);
			*(int*)params = AchievementId;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.AchievementDetails'!
void**)(params + 4) = OutAchievementDetails;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutAchievementDetails = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.AchievementDetails'!
void**)(params + 4);
			free(params);
		}
		void OnPlayerAchievementsChanged(int TitleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnPlayerAchievementsChanged");
			byte* params = (byte*)malloc(4);
			*(int*)params = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayerAchievementUnlocked(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnPlayerAchievementUnlocked");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnRegister");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnUnregister");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateAchievements()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_PlayerAchievements.UpdateAchievements");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
