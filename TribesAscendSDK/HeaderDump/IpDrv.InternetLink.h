#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.Info.h"
#include "IpDrv.InternetLink.IpAddr.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.InternetLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.InternetLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InternetLink : public Info
	{
	public:
		ADD_VAR(::IntProperty, DataPending, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, PrivateResolveInfo, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, RemoteSocket, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Port, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Socket, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ReceiveMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OutLineMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LinkMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, InLineMode, 0xFFFFFFFF)
		bool IsDataPending()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.IsDataPending");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ParseURL(ScriptArray<wchar_t> URL, ScriptArray<wchar_t>& Addr, int& PortNum, ScriptArray<wchar_t>& LevelName, ScriptArray<wchar_t>& EntryName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.ParseURL");
			byte* params = (byte*)malloc(56);
			*(ScriptArray<wchar_t>*)params = URL;
			*(ScriptArray<wchar_t>*)(params + 12) = Addr;
			*(int*)(params + 24) = PortNum;
			*(ScriptArray<wchar_t>*)(params + 28) = LevelName;
			*(ScriptArray<wchar_t>*)(params + 40) = EntryName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Addr = *(ScriptArray<wchar_t>*)(params + 12);
			PortNum = *(int*)(params + 24);
			LevelName = *(ScriptArray<wchar_t>*)(params + 28);
			EntryName = *(ScriptArray<wchar_t>*)(params + 40);
			auto returnVal = *(bool*)(params + 52);
			free(params);
			return returnVal;
		}
		void Resolve(ScriptArray<wchar_t> Domain)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.Resolve");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Domain;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetLastError()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.GetLastError");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> IpAddrToString(IpAddr Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.IpAddrToString");
			byte* params = (byte*)malloc(20);
			*(IpAddr*)params = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		bool StringToIpAddr(ScriptArray<wchar_t> Str, IpAddr& Addr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.StringToIpAddr");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Str;
			*(IpAddr*)(params + 12) = Addr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Addr = *(IpAddr*)(params + 12);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void GetLocalIP(IpAddr& Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.GetLocalIP");
			byte* params = (byte*)malloc(8);
			*(IpAddr*)params = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Arg = *(IpAddr*)params;
			free(params);
		}
		void Resolved(IpAddr Addr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.Resolved");
			byte* params = (byte*)malloc(8);
			*(IpAddr*)params = Addr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResolveFailed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.InternetLink.ResolveFailed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
