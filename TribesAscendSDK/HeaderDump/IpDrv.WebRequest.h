#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class WebRequest : public Object
	{
	public:
		enum ERequestType : byte
		{
			Request_GET = 0,
			Request_POST = 1,
			Request_MAX = 2,
		};
		ADD_STRUCT(ScriptString*, UserName, 84)
		ADD_STRUCT(ScriptString*, Password, 96)
		ADD_STRUCT(ScriptString*, URI, 72)
		ADD_STRUCT(WebRequest::ERequestType, RequestType, 124)
		ADD_STRUCT(ScriptString*, RemoteAddr, 60)
		ADD_STRUCT(int, ContentLength, 108)
		ADD_STRUCT(ScriptString*, ContentType, 112)
		ADD_STRUCT(Object::Map_Mirror, VariableMap, 188)
		ADD_STRUCT(Object::Map_Mirror, HeaderMap, 128)
		ScriptString* GetVariable(ScriptString* VariableName, ScriptString* DefaultValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetVariable");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = VariableName;
			*(ScriptString**)&params[12] = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		int GetVariableCount(ScriptString* VariableName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetVariableCount");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = VariableName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		ScriptString* GetVariableNumber(ScriptString* VariableName, int Number, ScriptString* DefaultValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetVariableNumber");
			byte params[40] = { NULL };
			*(ScriptString**)&params[0] = VariableName;
			*(int*)&params[12] = Number;
			*(ScriptString**)&params[16] = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[28];
		}
		ScriptString* DecodeBase64(ScriptString* Encoded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.DecodeBase64");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Encoded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* EncodeBase64(ScriptString* Decoded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.EncodeBase64");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Decoded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void AddHeader(ScriptString* HeaderName, ScriptString* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.AddHeader");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = HeaderName;
			*(ScriptString**)&params[12] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetHeader(ScriptString* HeaderName, ScriptString* DefaultValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetHeader");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = HeaderName;
			*(ScriptString**)&params[12] = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		void GetHeaders(ScriptArray<ScriptString*>& headers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetHeaders");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = headers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			headers = *(ScriptArray<ScriptString*>*)&params[0];
		}
		void AddVariable(ScriptString* VariableName, ScriptString* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.AddVariable");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = VariableName;
			*(ScriptString**)&params[12] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetVariables(ScriptArray<ScriptString*>& varNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetVariables");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = varNames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			varNames = *(ScriptArray<ScriptString*>*)&params[0];
		}
		void Dump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.Dump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessHeaderString(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.ProcessHeaderString");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DecodeFormData(ScriptString* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.DecodeFormData");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHexDigit(ScriptString* D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetHexDigit");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
	};
}
#undef ADD_STRUCT
