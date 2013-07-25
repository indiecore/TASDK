#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
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
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'PushModel'
		// Here lies the not-yet-implemented method 'HelpButton'
	};
}
#undef ADD_VAR
