#pragma once
#include "Core.Object.h"
#include "Engine.GameplayEventsWriter.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GenericParamListStatEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GenericParamListStatEntry." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GenericParamListStatEntry : public Object
	{
	public:
		ADD_OBJECT(GameplayEventsWriter, Writer)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'StatEvent'!
		void AddFloat(ScriptName ParamName, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.AddFloat");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParamName;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddInt(ScriptName ParamName, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.AddInt");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParamName;
			*(int*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddVector(ScriptName ParamName, Vector Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.AddVector");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = ParamName;
			*(Vector*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddString(ScriptName ParamName, ScriptArray<wchar_t> Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.AddString");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = ParamName;
			*(ScriptArray<wchar_t>*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetFloat(ScriptName ParamName, float& out_Float)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.GetFloat");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParamName;
			*(float*)(params + 8) = out_Float;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Float = *(float*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetInt(ScriptName ParamName, int& out_int)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.GetInt");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParamName;
			*(int*)(params + 8) = out_int;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_int = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetVector(ScriptName ParamName, Vector& out_vector)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.GetVector");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParamName;
			*(Vector*)(params + 8) = out_vector;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_vector = *(Vector*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetString(ScriptName ParamName, ScriptArray<wchar_t>& out_string)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.GetString");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParamName;
			*(ScriptArray<wchar_t>*)(params + 8) = out_string;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_string = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void CommitToDisk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GenericParamListStatEntry.CommitToDisk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
