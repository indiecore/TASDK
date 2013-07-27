#pragma once
#include "Engine.Info.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InternetLink : public Info
	{
	public:
		enum ELinkMode : byte
		{
			MODE_Text = 0,
			MODE_Line = 1,
			MODE_Binary = 2,
			MODE_MAX = 3,
		};
		enum EReceiveMode : byte
		{
			RMODE_Manual = 0,
			RMODE_Event = 1,
			RMODE_MAX = 2,
		};
		enum ELineMode : byte
		{
			LMODE_auto = 0,
			LMODE_DOS = 1,
			LMODE_UNIX = 2,
			LMODE_MAC = 3,
			LMODE_MAX = 4,
		};
		class IpAddr
		{
		public:
			ADD_STRUCT(int, Port, 4)
			ADD_STRUCT(int, Addr, 0)
		};
		ADD_STRUCT(int, DataPending, 496)
		ADD_STRUCT(Object::Pointer, PrivateResolveInfo, 492)
		ADD_STRUCT(Object::Pointer, RemoteSocket, 488)
		ADD_STRUCT(int, Port, 484)
		ADD_STRUCT(Object::Pointer, Socket, 480)
		ADD_STRUCT(InternetLink::EReceiveMode, ReceiveMode, 479)
		ADD_STRUCT(InternetLink::ELineMode, OutLineMode, 478)
		ADD_STRUCT(InternetLink::ELinkMode, LinkMode, 476)
		ADD_STRUCT(InternetLink::ELineMode, InLineMode, 477)
		bool IsDataPending()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.IsDataPending");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ParseURL(ScriptString* URL, ScriptString*& Addr, int& PortNum, ScriptString*& LevelName, ScriptString*& EntryName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.ParseURL");
			byte params[56] = { NULL };
			*(ScriptString**)&params[0] = URL;
			*(ScriptString**)&params[12] = Addr;
			*(int*)&params[24] = PortNum;
			*(ScriptString**)&params[28] = LevelName;
			*(ScriptString**)&params[40] = EntryName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Addr = *(ScriptString**)&params[12];
			PortNum = *(int*)&params[24];
			LevelName = *(ScriptString**)&params[28];
			EntryName = *(ScriptString**)&params[40];
			return *(bool*)&params[52];
		}
		void Resolve(ScriptString* Domain)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.Resolve");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Domain;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetLastError()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.GetLastError");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		ScriptString* IpAddrToString(InternetLink::IpAddr Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.IpAddrToString");
			byte params[20] = { NULL };
			*(InternetLink::IpAddr*)&params[0] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		bool StringToIpAddr(ScriptString* Str, InternetLink::IpAddr& Addr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.StringToIpAddr");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Str;
			*(InternetLink::IpAddr*)&params[12] = Addr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Addr = *(InternetLink::IpAddr*)&params[12];
			return *(bool*)&params[20];
		}
		void GetLocalIP(InternetLink::IpAddr& Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.GetLocalIP");
			byte params[8] = { NULL };
			*(InternetLink::IpAddr*)&params[0] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Arg = *(InternetLink::IpAddr*)&params[0];
		}
		void Resolved(InternetLink::IpAddr Addr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.Resolved");
			byte params[8] = { NULL };
			*(InternetLink::IpAddr*)&params[0] = Addr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResolveFailed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.ResolveFailed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
