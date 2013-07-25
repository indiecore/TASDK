#pragma once
#include "TribesGame__TrFlagBase.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrFlagCTF." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrFlagCTF : public TrFlagBase
	{
	public:
		ADD_VAR(::FloatProperty, m_YouHaveTheFlagReminderTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_ReturnedTimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_LastReturnedTime, 0xFFFFFFFF)
		void LogTaken(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.LogTaken");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogDropped(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.LogDropped");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.ClearHolder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.SendHome");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Returner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemindPlayerAboutFlagTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.RemindPlayerAboutFlagTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastTakenFromBaseMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.BroadcastTakenFromBaseMessage");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastTakenDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.BroadcastTakenDroppedMessage");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastCapturedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.BroadcastCapturedMessage");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.BroadcastReturnedMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagCTF.BroadcastDroppedMessage");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
