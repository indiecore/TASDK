#pragma once
#include "IpDrv.TcpLink.h"
#include "IpDrv.WebServer.h"
#include "IpDrv.WebApplication.h"
#include "IpDrv.WebResponse.h"
#include "IpDrv.WebRequest.h"
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
	class WebConnection : public TcpLink
	{
	public:
		ADD_STRUCT(int, ConnID, 584)
		ADD_STRUCT(int, MaxLineLength, 580)
		ADD_STRUCT(int, MaxValueLength, 576)
		ADD_STRUCT(int, RawBytesExpecting, 572)
		ADD_BOOL(bDelayCleanup, 568, 0x1)
		ADD_OBJECT(WebApplication, Application, 564)
		ADD_OBJECT(WebResponse, Response, 560)
		ADD_OBJECT(WebRequest, Request, 556)
		ADD_STRUCT(ScriptString*, ReceivedData, 544)
		ADD_OBJECT(WebServer, WebServer, 540)
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
		void ReceivedText(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ReceivedText");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceivedLine(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ReceivedLine");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessHead(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ProcessHead");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessGet(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ProcessGet");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessPost(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebConnection.ProcessPost");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
