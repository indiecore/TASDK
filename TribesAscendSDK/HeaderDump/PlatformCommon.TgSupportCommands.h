#pragma once
#include "Core.Object.h"
#include "Engine.WorldInfo.h"
#include "Engine.PlayerController.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TgSupportCommands : public Object
	{
	public:
		static const auto GC_OS_TYPE_BELOW_XP = 10300;
		static const auto GC_OS_TYPE_XP = 10301;
		static const auto GC_OS_TYPE_VISTA = 10303;
		static const auto GC_OS_TYPE_WIN7 = 10305;
		static const auto GC_OS_TYPE_WIN8 = 10307;
		enum GC_ALERT_PRIORITY : byte
		{
			GC_APT_MINIMAL = 0,
			GC_APT_NORMAL = 1,
			GC_APT_HIGH = 2,
			GC_APT_CRITICAL = 3,
			GC_APT_MAX = 4,
		};
		enum GC_CHAT_CHANNEL : byte
		{
			GC_CC_GLOBAL = 0,
			GC_CC_CLAN = 1,
			GC_CC_INSTANCE = 2,
			GC_CC_LOCAL_TEAM = 3,
			GC_CC_PARTY = 4,
			GC_CC_CITY = 5,
			GC_CC_PERSONAL = 6,
			GC_CC_PRIVATE_1 = 7,
			GC_CC_EOM_LOBBY = 8,
			GC_CC_SYSTEM = 9,
			GC_CC_TRADE = 10,
			GC_CC_LFG = 11,
			GC_CC_HELP = 12,
			GC_CC_VOIP_NEWS = 13,
			GC_CC_COUNT = 14,
			GC_CC_VOIP_ECHO = 15,
			GC_CC_VOIP_CONF = 16,
			GC_CC_COMBAT = 17,
			GC_CC_EMOTE = 18,
			GC_CC_INVALID = 19,
			GC_CC_LAST = 20,
			GC_CC_MAX = 21,
		};
		enum GC_STEAM_TXN_TYPES : byte
		{
			GC_STT_INVALID = 0,
			GC_STT_GETUSERINFO = 1,
			GC_STT_INIT = 2,
			GC_STT_FINALIZE = 3,
			GC_STT_DECLINE = 4,
			GC_STT_MAX = 5,
		};
		ADD_OBJECT(WorldInfo, WorldInfo, 64)
		ADD_OBJECT(PlayerController, PC, 60)
		void gmMatchForce(int nQueueId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34397);
			byte params[4] = { NULL };
			*(int*)params = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void gmMatchNext(int nMapId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34399);
			byte params[4] = { NULL };
			*(int*)params = nMapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void gmCommand(ScriptString* sCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34401);
			byte params[12] = { NULL };
			*(ScriptString**)params = sCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void gmC(ScriptString* sCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34403);
			byte params[12] = { NULL };
			*(ScriptString**)params = sCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GPerfDebugFeet(int feet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34405);
			byte params[4] = { NULL };
			*(int*)params = feet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GPerfDebugSkips(int skips)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34407);
			byte params[4] = { NULL };
			*(int*)params = skips;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GPerfDebugRelevMode(int Mode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34409);
			byte params[4] = { NULL };
			*(int*)params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scLog(ScriptString* LogName, bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34411);
			byte params[16] = { NULL };
			*(ScriptString**)params = LogName;
			*(bool*)&params[12] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scLogMark(ScriptString* Comment)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34415);
			byte params[12] = { NULL };
			*(ScriptString**)params = Comment;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scStartGame(ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34417);
			byte params[12] = { NULL };
			*(ScriptString**)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scEndGame(ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34420);
			byte params[12] = { NULL };
			*(ScriptString**)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scScore(int nTeam, int nCount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34423);
			byte params[8] = { NULL };
			*(int*)params = nTeam;
			*(int*)&params[4] = nCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scTime(int nSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34427);
			byte params[4] = { NULL };
			*(int*)params = nSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scTimer(ScriptString* sCommand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34430);
			byte params[12] = { NULL };
			*(ScriptString**)params = sCommand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scDemoRec()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34433);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void scDemoStop()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34434);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void scPerfDebugFeet(int feet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34435);
			byte params[4] = { NULL };
			*(int*)params = feet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scPerfDebugSkip(int skips)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34437);
			byte params[4] = { NULL };
			*(int*)params = skips;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void scPerfDebugRelevMode(int Mode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34439);
			byte params[4] = { NULL };
			*(int*)params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
