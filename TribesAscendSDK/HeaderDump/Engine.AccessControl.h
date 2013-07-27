#pragma once
#include "Engine.PlayerController.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.Info.h"
#include "Engine.Controller.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AccessControl : public Info
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, IPPolicies, 476)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, BannedIDs, 488)
		ADD_BOOL(bDontAddDefaultAdmin, 684, 0x1)
		ADD_STRUCT(ScriptString*, ACDescText, 648)
		ADD_STRUCT(ScriptString*, ACDisplayText, 612)
		ADD_STRUCT(ScriptString*, GamePassword, 600)
		ADD_STRUCT(ScriptString*, AdminPassword, 588)
		ADD_OBJECT(ScriptClass, AdminClass, 584)
		ADD_STRUCT(ScriptString*, IdleKickReason, 572)
		ADD_STRUCT(ScriptString*, DefaultKickReason, 560)
		ADD_STRUCT(ScriptString*, KickedMsg, 548)
		ADD_STRUCT(ScriptString*, SessionBanned, 536)
		ADD_STRUCT(ScriptString*, NeedPassword, 524)
		ADD_STRUCT(ScriptString*, WrongPassword, 512)
		ADD_STRUCT(ScriptString*, IPBanned, 500)
		bool IsAdmin(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5697);
			byte params[8] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetAdminPassword(ScriptString* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5702);
			byte params[16] = { NULL };
			*(ScriptString**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetGamePassword(ScriptString* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5705);
			byte params[12] = { NULL };
			*(ScriptString**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RequiresPassword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5707);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class Controller* GetControllerFromString(ScriptString* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5709);
			byte params[16] = { NULL };
			*(ScriptString**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[12];
		}
		void Kick(ScriptString* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5720);
			byte params[12] = { NULL };
			*(ScriptString**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickBan(ScriptString* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5723);
			byte params[12] = { NULL };
			*(ScriptString**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ForceKickPlayer(class PlayerController* C, ScriptString* KickReason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5733);
			byte params[20] = { NULL };
			*(class PlayerController**)params = C;
			*(ScriptString**)&params[4] = KickReason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool KickPlayer(class PlayerController* C, ScriptString* KickReason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5737);
			byte params[20] = { NULL };
			*(class PlayerController**)params = C;
			*(ScriptString**)&params[4] = KickReason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool AdminLogin(class PlayerController* P, ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5741);
			byte params[20] = { NULL };
			*(class PlayerController**)params = P;
			*(ScriptString**)&params[4] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool AdminLogout(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5745);
			byte params[8] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AdminEntered(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5749);
			byte params[4] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminExited(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5752);
			byte params[4] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ParseAdminOptions(ScriptString* Options)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5755);
			byte params[16] = { NULL };
			*(ScriptString**)params = Options;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ValidLogin(ScriptString* UserName, ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5762);
			byte params[28] = { NULL };
			*(ScriptString**)params = UserName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void PreLogin(ScriptString* Options, ScriptString* Address, ScriptString*& OutError, bool bSpectator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5766);
			byte params[40] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = Address;
			*(ScriptString**)&params[24] = OutError;
			*(bool*)&params[36] = bSpectator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)&params[24];
		}
		bool CheckIPPolicy(ScriptString* Address)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5775);
			byte params[16] = { NULL };
			*(ScriptString**)params = Address;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsIDBanned(OnlineSubsystem::UniqueNetId& NetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5784);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = NetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NetId = *(OnlineSubsystem::UniqueNetId*)params;
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
