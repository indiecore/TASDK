#pragma once
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
	};
}
#undef ADD_VAR
