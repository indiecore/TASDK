#pragma once
#include "Core__Object.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPartyManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrPartyManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bCreatedParty, 0x1)
		ADD_VAR(::StrProperty, InvitingPlayer, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'InParty'
		// Here lies the not-yet-implemented method 'AmLeader'
		// Here lies the not-yet-implemented method 'CanInvite'
		// Here lies the not-yet-implemented method 'GetMemberCap'
		// Here lies the not-yet-implemented method 'GetMemberCount'
		// Here lies the not-yet-implemented method 'Kick'
		// Here lies the not-yet-implemented method 'SendInvite'
		// Here lies the not-yet-implemented method 'GetMemberId'
		// Here lies the not-yet-implemented method 'GetMemberName'
		// Here lies the not-yet-implemented method 'ActiveMember'
		// Here lies the not-yet-implemented method 'Leave'
		// Here lies the not-yet-implemented method 'AcceptInvite'
		// Here lies the not-yet-implemented method 'GetLeaderName'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'ShowInvitation'
		// Here lies the not-yet-implemented method 'InvitationPopup'
		// Here lies the not-yet-implemented method 'InvitationComplete'
		// Here lies the not-yet-implemented method 'OnUpdate'
		// Here lies the not-yet-implemented method 'LeaveParty'
	};
}
#undef ADD_VAR
