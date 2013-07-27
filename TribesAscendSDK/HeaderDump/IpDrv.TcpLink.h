#pragma once
#include "IpDrv.InternetLink.h"
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
	class TcpLink : public InternetLink
	{
	public:
		enum ELinkState : byte
		{
			STATE_Initialized = 0,
			STATE_Ready = 1,
			STATE_Listening = 2,
			STATE_Connecting = 3,
			STATE_Connected = 4,
			STATE_ListenClosePending = 5,
			STATE_ConnectClosePending = 6,
			STATE_ListenClosing = 7,
			STATE_ConnectClosing = 8,
			STATE_MAX = 9,
		};
		ADD_STRUCT(ScriptArray<byte>, SendFIFO, 516)
		ADD_STRUCT(ScriptString*, RecvBuf, 528)
		ADD_OBJECT(ScriptClass, AcceptClass, 512)
		ADD_STRUCT(InternetLink::IpAddr, RemoteAddr, 504)
		ADD_STRUCT(TcpLink::ELinkState, LinkState, 500)
		int BindPort(int PortNum, bool bUseNextAvailable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.BindPort");
			byte params[12] = { NULL };
			*(int*)&params[0] = PortNum;
			*(bool*)&params[4] = bUseNextAvailable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool Listen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Listen");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool Open(InternetLink::IpAddr Addr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Open");
			byte params[12] = { NULL };
			*(InternetLink::IpAddr*)&params[0] = Addr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Close()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Close");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsConnected()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.IsConnected");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int SendText(ScriptString* Str)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.SendText");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Str;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int SendBinary(int Count, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.SendBinary");
			byte params[9] = { NULL };
			*(int*)&params[0] = Count;
			params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[260];
		}
		int ReadText(ScriptString*& Str)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReadText");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Str;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Str = *(ScriptString**)&params[0];
			return *(int*)&params[12];
		}
		int ReadBinary(int Count, byte& B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReadBinary");
			byte params[9] = { NULL };
			*(int*)&params[0] = Count;
			params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			B = params[4];
			return *(int*)&params[260];
		}
		void Accepted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Accepted");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Opened()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Opened");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Closed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Closed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedText(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReceivedText");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceivedLine(ScriptString* Line)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReceivedLine");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Line;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceivedBinary(int Count, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReceivedBinary");
			byte params[5] = { NULL };
			*(int*)&params[0] = Count;
			params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
