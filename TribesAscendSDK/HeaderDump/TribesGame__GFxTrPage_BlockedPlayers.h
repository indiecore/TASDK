#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_BlockedPlayers." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_BlockedPlayers : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, FlyoutTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UnblockOption, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BlockedStatus, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BlockSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BlockOption, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForFriendRemovePopup, 0x2)
		ADD_VAR(::BoolProperty, bWaitingForFriendAddPopup, 0x1)
		ADD_VAR(::IntProperty, RemovingIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevPlayerId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FocusedIndex, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'ModifyFocus'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'RefreshButtons'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'FindNextBlocked'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
	};
}
#undef ADD_VAR
