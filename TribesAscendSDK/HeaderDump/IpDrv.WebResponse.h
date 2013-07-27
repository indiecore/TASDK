#pragma once
#include "Core.Object.h"
#include "IpDrv.WebConnection.h"
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
	class WebResponse : public Object
	{
	public:
		ADD_OBJECT(WebConnection, Connection, 156)
		ADD_STRUCT(ScriptArray<ScriptString*>, headers, 60)
		ADD_BOOL(bSentResponse, 160, 0x2)
		ADD_BOOL(bSentText, 160, 0x1)
		ADD_STRUCT(ScriptString*, CharSet, 144)
		ADD_STRUCT(ScriptString*, IncludePath, 132)
		ADD_STRUCT(Object::Map_Mirror, ReplacementMap, 72)
		void Subst(ScriptString* Variable, ScriptString* Value, bool bClear)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.Subst");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = Variable;
			*(ScriptString**)&params[12] = Value;
			*(bool*)&params[24] = bClear;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IncludeUHTM(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.IncludeUHTM");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool FileExists(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.FileExists");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IncludeBinaryFile(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.IncludeBinaryFile");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void ClearSubst()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.ClearSubst");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* LoadParsedUHTM(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.LoadParsedUHTM");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* GetHTTPExpiration(int OffsetSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.GetHTTPExpiration");
			byte params[16] = { NULL };
			*(int*)&params[0] = OffsetSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void Dump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.Dump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendText(ScriptString* Text, bool bNoCRLF)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendText");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Text;
			*(bool*)&params[12] = bNoCRLF;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendBinary(int Count, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendBinary");
			byte params[5] = { NULL };
			*(int*)&params[0] = Count;
			params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SendCachedFile(ScriptString* Filename, ScriptString* ContentType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendCachedFile");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			*(ScriptString**)&params[12] = ContentType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void FailAuthentication(ScriptString* Realm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.FailAuthentication");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Realm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HTTPResponse(ScriptString* Header)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.HTTPResponse");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Header;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HTTPHeader(ScriptString* Header)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.HTTPHeader");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Header;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddHeader(ScriptString* Header, bool bReplace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.AddHeader");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Header;
			*(bool*)&params[12] = bReplace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendHeaders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendHeaders");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HTTPError(int ErrorNum, ScriptString* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.HTTPError");
			byte params[16] = { NULL };
			*(int*)&params[0] = ErrorNum;
			*(ScriptString**)&params[4] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendStandardHeaders(ScriptString* ContentType, bool bCache)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SendStandardHeaders");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = ContentType;
			*(bool*)&params[12] = bCache;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Redirect(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.Redirect");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SentText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SentText");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SentResponse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebResponse.SentResponse");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
