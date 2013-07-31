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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34054);
			byte params[12] = { NULL };
			*(int*)params = PortNum;
			*(bool*)&params[4] = bUseNextAvailable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool Listen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34058);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool Open(InternetLink::IpAddr Addr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34060);
			byte params[12] = { NULL };
			*(InternetLink::IpAddr*)params = Addr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool Close()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34063);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsConnected()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34065);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int SendText(ScriptString* Str)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34067);
			byte params[16] = { NULL };
			*(ScriptString**)params = Str;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int SendBinary(int Count, byte B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34070);
			byte params[9] = { NULL };
			*(int*)params = Count;
			params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[260];
		}
		int ReadText(ScriptString*& Str)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34074);
			byte params[16] = { NULL };
			*(ScriptString**)params = Str;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Str = *(ScriptString**)params;
			return *(int*)&params[12];
		}
		int ReadBinary(int Count, byte& B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34077);
			byte params[9] = { NULL };
			*(int*)params = Count;
			params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			B = params[4];
			return *(int*)&params[260];
		}
		void Accepted()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34081);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Opened()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34082);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Closed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34083);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedText(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34084);
			byte params[12] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceivedLine(ScriptString* Line)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34086);
			byte params[12] = { NULL };
			*(ScriptString**)params = Line;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceivedBinary(int Count, byte B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34088);
			byte params[5] = { NULL };
			*(int*)params = Count;
			params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
