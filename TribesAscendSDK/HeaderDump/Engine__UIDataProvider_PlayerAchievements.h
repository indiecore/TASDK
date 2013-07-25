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
		// Here lies the not-yet-implemented method 'GetTotalGamerScore'
		// Here lies the not-yet-implemented method 'GetMaxTotalGamerScore'
		// Here lies the not-yet-implemented method 'PopulateAchievementIcons'
		// Here lies the not-yet-implemented method 'GetAchievementIconPathName'
		// Here lies the not-yet-implemented method 'GetAchievementDetails'
		// Here lies the not-yet-implemented method 'OnPlayerAchievementsChanged'
		// Here lies the not-yet-implemented method 'OnPlayerAchievementUnlocked'
		// Here lies the not-yet-implemented method 'OnRegister'
		// Here lies the not-yet-implemented method 'OnUnregister'
		// Here lies the not-yet-implemented method 'OnLoginChange'
		// Here lies the not-yet-implemented method 'UpdateAchievements'
	};
}
#undef ADD_STRUCT
