#pragma once
#include "Engine__UIDataProvider_OnlinePlayerDataBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlineFriends." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_OnlineFriends." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlineFriends : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_VAR(::StrProperty, BusyText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AwayText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OnlineText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OfflineText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bHasInvitedYouCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bHaveInvitedCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bHasVoiceSupportCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsJoinableCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsPlayingThisGameCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsPlayingCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsOnlineCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendStateCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PresenceInfoCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NickNameCol, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
