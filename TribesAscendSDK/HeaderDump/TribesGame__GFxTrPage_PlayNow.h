#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_PlayNow." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_PlayNow : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, SeasonUpcomingSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NoFriendsOnlineLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RegionsSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RegionsLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RankedLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CustomServerLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, JoinFriendLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, JoinFriendInGameSubLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, JoinFriendSubLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CustomServerSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ComingSoonSubtext, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetMeshEnumFromVV'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'RefreshButtons'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'RemoveDuplicateQueues'
		// Here lies the not-yet-implemented method 'HaveDuplicates'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'TakeFocus'
	};
}
#undef ADD_VAR
