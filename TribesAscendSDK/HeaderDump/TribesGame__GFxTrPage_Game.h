#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Game." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Game : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, strExitMatch, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, strManageServers, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, strSettings, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, strStore, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, strSocial, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, strParty, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRemovePartyTemp, 0x1)
		ADD_VAR(::IntProperty, TeamLoadoutNum, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
