#pragma once
#include "Core.Object.h"
#include "Engine.WorldInfo.h"
#include "Engine.PlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PlatformCommon.TgSupportCommands." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TgSupportCommands : public Object
	{
	public:
		ADD_OBJECT(WorldInfo, WorldInfo)
		ADD_OBJECT(PlayerController, PC)
		void gmMatchForce(int nQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.gmMatchForce");
			byte* params = (byte*)malloc(4);
			*(int*)params = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void gmMatchNext(int nMapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.gmMatchNext");
			byte* params = (byte*)malloc(4);
			*(int*)params = nMapId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void gmCommand(ScriptArray<wchar_t> sCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.gmCommand");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = sCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void gmC(ScriptArray<wchar_t> sCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.gmC");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = sCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GPerfDebugFeet(int feet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.GPerfDebugFeet");
			byte* params = (byte*)malloc(4);
			*(int*)params = feet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GPerfDebugSkips(int skips)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.GPerfDebugSkips");
			byte* params = (byte*)malloc(4);
			*(int*)params = skips;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GPerfDebugRelevMode(int Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.GPerfDebugRelevMode");
			byte* params = (byte*)malloc(4);
			*(int*)params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scLog(ScriptArray<wchar_t> LogName, bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scLog");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = LogName;
			*(bool*)(params + 12) = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scLogMark(ScriptArray<wchar_t> Comment)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scLogMark");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Comment;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scStartGame(ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scStartGame");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scEndGame(ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scEndGame");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scScore(int nTeam, int nCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scScore");
			byte* params = (byte*)malloc(8);
			*(int*)params = nTeam;
			*(int*)(params + 4) = nCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scTime(int nSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scTime");
			byte* params = (byte*)malloc(4);
			*(int*)params = nSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scTimer(ScriptArray<wchar_t> sCommand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scTimer");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = sCommand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scDemoRec()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scDemoRec");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void scDemoStop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scDemoStop");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void scPerfDebugFeet(int feet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scPerfDebugFeet");
			byte* params = (byte*)malloc(4);
			*(int*)params = feet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scPerfDebugSkip(int skips)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scPerfDebugSkip");
			byte* params = (byte*)malloc(4);
			*(int*)params = skips;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void scPerfDebugRelevMode(int Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgSupportCommands.scPerfDebugRelevMode");
			byte* params = (byte*)malloc(4);
			*(int*)params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
