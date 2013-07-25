#pragma once
#include "TribesGame__TrObject.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrFriendManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrFriendManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrFriendManager : public TrObject
	{
	public:
		ADD_VAR(::BoolProperty, AddFriendSuccess, 0x1)
		ADD_VAR(::StrProperty, RecentlyAddedFriend, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, GFxList)
		ADD_VAR(::IntProperty, GFxCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevBlockedCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevFollowerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevFriendCount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'RequestFriendsList'
		// Here lies the not-yet-implemented method 'AddFriend'
		// Here lies the not-yet-implemented method 'JoinFriend'
		// Here lies the not-yet-implemented method 'IgnoreFriend'
		// Here lies the not-yet-implemented method 'RemoveFriend'
		// Here lies the not-yet-implemented method 'Update'
		// Here lies the not-yet-implemented method 'RemoveFromList'
		// Here lies the not-yet-implemented method 'GetOnlineFriendCount'
		// Here lies the not-yet-implemented method 'GetInGameFriendCount'
		// Here lies the not-yet-implemented method 'GetOnlineFollowerCount'
		// Here lies the not-yet-implemented method 'IsFriend'
		// Here lies the not-yet-implemented method 'GetFriendListIndex'
		// Here lies the not-yet-implemented method 'AddFriendScoreboard'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
