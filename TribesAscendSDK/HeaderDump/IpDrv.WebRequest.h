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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33102);
			byte params[36] = { NULL };
			*(ScriptString**)params = VariableName;
			*(ScriptString**)&params[12] = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		int GetVariableCount(ScriptString* VariableName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33104);
			byte params[16] = { NULL };
			*(ScriptString**)params = VariableName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		ScriptString* GetVariableNumber(ScriptString* VariableName, int Number, ScriptString* DefaultValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33106);
			byte params[40] = { NULL };
			*(ScriptString**)params = VariableName;
			*(int*)&params[12] = Number;
			*(ScriptString**)&params[16] = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[28];
		}
		ScriptString* DecodeBase64(ScriptString* Encoded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34140);
			byte params[24] = { NULL };
			*(ScriptString**)params = Encoded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* EncodeBase64(ScriptString* Decoded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34143);
			byte params[24] = { NULL };
			*(ScriptString**)params = Decoded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void AddHeader(ScriptString* HeaderName, ScriptString* Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34146);
			byte params[24] = { NULL };
			*(ScriptString**)params = HeaderName;
			*(ScriptString**)&params[12] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetHeader(ScriptString* HeaderName, ScriptString* DefaultValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34149);
			byte params[36] = { NULL };
			*(ScriptString**)params = HeaderName;
			*(ScriptString**)&params[12] = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		void GetHeaders(ScriptArray<ScriptString*>& headers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34153);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = headers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			headers = *(ScriptArray<ScriptString*>*)params;
		}
		void AddVariable(ScriptString* VariableName, ScriptString* Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34156);
			byte params[24] = { NULL };
			*(ScriptString**)params = VariableName;
			*(ScriptString**)&params[12] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetVariables(ScriptArray<ScriptString*>& varNames)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34165);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = varNames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			varNames = *(ScriptArray<ScriptString*>*)params;
		}
		void Dump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34168);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessHeaderString(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34169);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DecodeFormData(ScriptString* Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34172);
			byte params[12] = { NULL };
			*(ScriptString**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHexDigit(ScriptString* D)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34181);
			byte params[16] = { NULL };
			*(ScriptString**)params = D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
	};
}
#undef ADD_STRUCT
