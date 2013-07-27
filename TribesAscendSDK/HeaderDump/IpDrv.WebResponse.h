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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33108);
			byte params[28] = { NULL };
			*(ScriptString**)params = Variable;
			*(ScriptString**)&params[12] = Value;
			*(bool*)&params[24] = bClear;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IncludeUHTM(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33109);
			byte params[16] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool FileExists(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33117);
			byte params[16] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IncludeBinaryFile(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33119);
			byte params[16] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void ClearSubst()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34195);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* LoadParsedUHTM(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34198);
			byte params[24] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* GetHTTPExpiration(int OffsetSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34201);
			byte params[16] = { NULL };
			*(int*)params = OffsetSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void Dump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34204);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendText(ScriptString* Text, bool bNoCRLF)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34205);
			byte params[16] = { NULL };
			*(ScriptString**)params = Text;
			*(bool*)&params[12] = bNoCRLF;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendBinary(int Count, byte B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34208);
			byte params[5] = { NULL };
			*(int*)params = Count;
			params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SendCachedFile(ScriptString* Filename, ScriptString* ContentType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34211);
			byte params[28] = { NULL };
			*(ScriptString**)params = Filename;
			*(ScriptString**)&params[12] = ContentType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void FailAuthentication(ScriptString* Realm)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34215);
			byte params[12] = { NULL };
			*(ScriptString**)params = Realm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HTTPResponse(ScriptString* Header)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34217);
			byte params[12] = { NULL };
			*(ScriptString**)params = Header;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HTTPHeader(ScriptString* Header)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34219);
			byte params[12] = { NULL };
			*(ScriptString**)params = Header;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddHeader(ScriptString* Header, bool bReplace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34221);
			byte params[16] = { NULL };
			*(ScriptString**)params = Header;
			*(bool*)&params[12] = bReplace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendHeaders()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34228);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HTTPError(int ErrorNum, ScriptString* Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34230);
			byte params[16] = { NULL };
			*(int*)params = ErrorNum;
			*(ScriptString**)&params[4] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendStandardHeaders(ScriptString* ContentType, bool bCache)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34233);
			byte params[16] = { NULL };
			*(ScriptString**)params = ContentType;
			*(bool*)&params[12] = bCache;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Redirect(ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34237);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SentText()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34239);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool SentResponse()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34241);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
