#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Social." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Social : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, FollowersOnlineSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendsOfflineSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendsOnlineSubtext, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'ShowModel'
	};
}
#undef ADD_VAR
