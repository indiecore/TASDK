#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_PartyInvite." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_PartyInvite : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, MemberName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Action_InviteFailed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Action_SendMessage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Action_InviteSent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Action_ByName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'ShowModel'
	};
}
#undef ADD_VAR
