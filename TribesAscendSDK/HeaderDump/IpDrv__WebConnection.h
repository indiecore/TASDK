#pragma once
#include "IpDrv__WebServer.h"
#include "IpDrv__TcpLink.h"
#include "IpDrv__WebApplication.h"
#include "IpDrv__WebResponse.h"
#include "IpDrv__WebRequest.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebConnection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.WebConnection." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WebConnection : public TcpLink
	{
	public:
		ADD_VAR(::IntProperty, ConnID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLineLength, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxValueLength, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RawBytesExpecting, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDelayCleanup, 0x1)
		ADD_OBJECT(WebApplication, Application)
		ADD_OBJECT(WebResponse, Response)
		ADD_OBJECT(WebRequest, Request)
		ADD_VAR(::StrProperty, ReceivedData, 0xFFFFFFFF)
		ADD_OBJECT(WebServer, WebServer)
		void Accepted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.Accepted");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Closed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.Closed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ReceivedText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceivedLine(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ReceivedLine");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessHead(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ProcessHead");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessGet(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ProcessGet");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessPost(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ProcessPost");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateResponseObject()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.CreateResponseObject");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndOfHeaders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.EndOfHeaders");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckRawBytes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.CheckRawBytes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Cleanup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.Cleanup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsHanging()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.IsHanging");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
