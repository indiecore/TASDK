#pragma once
#include "Core.Object.h"
#include "IpDrv.WebConnection.h"
#include "Core.Object.Map_Mirror.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebResponse." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.WebResponse." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.WebResponse." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WebResponse : public Object
	{
	public:
		ADD_OBJECT(WebConnection, Connection)
		ADD_VAR(::BoolProperty, bSentResponse, 0x2)
		ADD_VAR(::BoolProperty, bSentText, 0x1)
		ADD_VAR(::StrProperty, CharSet, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IncludePath, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Map_Mirror>, ReplacementMap, 0xFFFFFFFF)
		void Subst(ScriptArray<wchar_t> Variable, ScriptArray<wchar_t> Value, bool bClear)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.Subst");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Variable;
			*(ScriptArray<wchar_t>*)(params + 12) = Value;
			*(bool*)(params + 24) = bClear;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IncludeUHTM(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.IncludeUHTM");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool FileExists(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.FileExists");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool IncludeBinaryFile(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.IncludeBinaryFile");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void ClearSubst()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.ClearSubst");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> LoadParsedUHTM(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.LoadParsedUHTM");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetHTTPExpiration(int OffsetSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.GetHTTPExpiration");
			byte* params = (byte*)malloc(16);
			*(int*)params = OffsetSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void Dump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.Dump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendText(ScriptArray<wchar_t> Text, bool bNoCRLF)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendText");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Text;
			*(bool*)(params + 12) = bNoCRLF;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendBinary(int Count, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendBinary");
			byte* params = (byte*)malloc(5);
			*(int*)params = Count;
			*(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SendCachedFile(ScriptArray<wchar_t> Filename, ScriptArray<wchar_t> ContentType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendCachedFile");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Filename;
			*(ScriptArray<wchar_t>*)(params + 12) = ContentType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void FailAuthentication(ScriptArray<wchar_t> Realm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.FailAuthentication");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Realm;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HTTPResponse(ScriptArray<wchar_t> Header)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.HTTPResponse");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Header;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HTTPHeader(ScriptArray<wchar_t> Header)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.HTTPHeader");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Header;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddHeader(ScriptArray<wchar_t> Header, bool bReplace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.AddHeader");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Header;
			*(bool*)(params + 12) = bReplace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendHeaders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendHeaders");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HTTPError(int ErrorNum, ScriptArray<wchar_t> Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.HTTPError");
			byte* params = (byte*)malloc(16);
			*(int*)params = ErrorNum;
			*(ScriptArray<wchar_t>*)(params + 4) = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendStandardHeaders(ScriptArray<wchar_t> ContentType, bool bCache)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendStandardHeaders");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = ContentType;
			*(bool*)(params + 12) = bCache;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Redirect(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.Redirect");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SentText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SentText");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SentResponse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SentResponse");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
