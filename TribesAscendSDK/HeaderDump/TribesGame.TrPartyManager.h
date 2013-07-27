#pragma once
#include "GFxUI.GFxObject.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrPartyManager : public Object
	{
	public:
		ADD_BOOL(bCreatedParty, 60, 0x1)
		ADD_STRUCT(ScriptString*, InvitingPlayer, 64)
		bool InParty()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54628);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool AmLeader()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54630);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanInvite()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59813);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetMemberCap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59815);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetMemberCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59817);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool Kick(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59853);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SendInvite(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59878);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetMemberId(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59908);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		ScriptString* GetMemberName(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59925);
			byte params[16] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool ActiveMember(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59927);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool Leave()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100577);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool AcceptInvite()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100582);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		ScriptString* GetLeaderName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100584);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100587);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowInvitation(ScriptString* LeaderName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100588);
			byte params[12] = { NULL };
			*(ScriptString**)params = LeaderName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InvitationPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100590);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InvitationComplete(int Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100595);
			byte params[4] = { NULL };
			*(int*)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100597);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveParty(bool bHandle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100598);
			byte params[4] = { NULL };
			*(bool*)params = bHandle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
