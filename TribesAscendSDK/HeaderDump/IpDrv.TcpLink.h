#pragma once
#include "IpDrv.InternetLink.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.TcpLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.TcpLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.TcpLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TcpLink : public InternetLink
	{
	public:
		ADD_VAR(::StrProperty, RecvBuf, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, AcceptClass)
		// WARNING: Unknown structure type 'ScriptStruct IpDrv.InternetLink.IpAddr' for the property named 'RemoteAddr'!
		ADD_VAR(::ByteProperty, LinkState, 0xFFFFFFFF)
		int BindPort(int PortNum, bool bUseNextAvailable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.BindPort");
			byte* params = (byte*)malloc(12);
			*(int*)params = PortNum;
			*(bool*)(params + 4) = bUseNextAvailable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool Listen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Listen");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool Open(
// WARNING: Unknown structure type 'ScriptStruct IpDrv.InternetLink.IpAddr'!
void* Addr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Open");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct IpDrv.InternetLink.IpAddr'!
void**)params = Addr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool Close()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.Close");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsConnected()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.IsConnected");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int SendText(ScriptArray<wchar_t> Str)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.SendText");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Str;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int SendBinary(int Count, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.SendBinary");
			byte* params = (byte*)malloc(9);
			*(int*)params = Count;
			*(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 260);
			free(params);
			return returnVal;
		}
		int ReadText(ScriptArray<wchar_t>& Str)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReadText");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Str;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Str = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int ReadBinary(int Count, byte& B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReadBinary");
			byte* params = (byte*)malloc(9);
			*(int*)params = Count;
			*(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			B = *(params + 4);
			auto returnVal = *(int*)(params + 260);
			free(params);
			return returnVal;
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
		void ReceivedText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReceivedText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceivedLine(ScriptArray<wchar_t> Line)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReceivedLine");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Line;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceivedBinary(int Count, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.TcpLink.ReceivedBinary");
			byte* params = (byte*)malloc(5);
			*(int*)params = Count;
			*(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
