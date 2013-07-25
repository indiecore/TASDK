#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.WebRequest." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.WebRequest." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WebRequest : public Object
	{
	public:
		ADD_VAR(::StrProperty, UserName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Password, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URI, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RequestType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RemoteAddr, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ContentLength, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ContentType, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'VariableMap'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'HeaderMap'!
		ScriptArray<wchar_t> GetVariable(ScriptArray<wchar_t> VariableName, ScriptArray<wchar_t> DefaultValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetVariable");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = VariableName;
			*(ScriptArray<wchar_t>*)(params + 12) = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		int GetVariableCount(ScriptArray<wchar_t> VariableName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetVariableCount");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = VariableName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetVariableNumber(ScriptArray<wchar_t> VariableName, int Number, ScriptArray<wchar_t> DefaultValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetVariableNumber");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = VariableName;
			*(int*)(params + 12) = Number;
			*(ScriptArray<wchar_t>*)(params + 16) = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 28);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> DecodeBase64(ScriptArray<wchar_t> Encoded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.DecodeBase64");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Encoded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> EncodeBase64(ScriptArray<wchar_t> Decoded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.EncodeBase64");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Decoded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddHeader(ScriptArray<wchar_t> HeaderName, ScriptArray<wchar_t> Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.AddHeader");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = HeaderName;
			*(ScriptArray<wchar_t>*)(params + 12) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetHeader(ScriptArray<wchar_t> HeaderName, ScriptArray<wchar_t> DefaultValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetHeader");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = HeaderName;
			*(ScriptArray<wchar_t>*)(params + 12) = DefaultValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		void GetHeaders(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& headers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetHeaders");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = headers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			headers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void AddVariable(ScriptArray<wchar_t> VariableName, ScriptArray<wchar_t> Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.AddVariable");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = VariableName;
			*(ScriptArray<wchar_t>*)(params + 12) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetVariables(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& varNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetVariables");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = varNames;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			varNames = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void Dump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.Dump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessHeaderString(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.ProcessHeaderString");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DecodeFormData(ScriptArray<wchar_t> Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.DecodeFormData");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetHexDigit(ScriptArray<wchar_t> D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.WebRequest.GetHexDigit");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = D;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
