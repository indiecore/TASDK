#pragma once
#include "Engine.UIDataStore_StringAliasMap.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataStore_StringAliasBindingMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataStore_StringAliasBindingMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_StringAliasBindingMap : public UIDataStore_StringAliasMap
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'CommandToBindNames'!
		ADD_VAR(::IntProperty, FakePlatform, 0xFFFFFFFF)
		int GetStringWithFieldName(ScriptArray<wchar_t> FieldName, ScriptArray<wchar_t>& MappedString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringAliasBindingMap.GetStringWithFieldName");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 12) = MappedString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MappedString = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(int*)(params + 24);
			free(params);
			return returnVal;
		}
		int GetBoundStringWithFieldName(ScriptArray<wchar_t> FieldName, ScriptArray<wchar_t>& MappedString, int& StartIndex, ScriptArray<wchar_t>& BindString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringAliasBindingMap.GetBoundStringWithFieldName");
			byte* params = (byte*)malloc(44);
			*(ScriptArray<wchar_t>*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 12) = MappedString;
			*(int*)(params + 24) = StartIndex;
			*(ScriptArray<wchar_t>*)(params + 28) = BindString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MappedString = *(ScriptArray<wchar_t>*)(params + 12);
			StartIndex = *(int*)(params + 24);
			BindString = *(ScriptArray<wchar_t>*)(params + 28);
			auto returnVal = *(int*)(params + 40);
			free(params);
			return returnVal;
		}
		bool FindMappingInBoundKeyCache(ScriptArray<wchar_t> Command, ScriptArray<wchar_t>& MappingStr, int& FieldIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringAliasBindingMap.FindMappingInBoundKeyCache");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Command;
			*(ScriptArray<wchar_t>*)(params + 12) = MappingStr;
			*(int*)(params + 24) = FieldIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MappingStr = *(ScriptArray<wchar_t>*)(params + 12);
			FieldIndex = *(int*)(params + 24);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void AddMappingToBoundKeyCache(ScriptArray<wchar_t> Command, ScriptArray<wchar_t> MappingStr, int FieldIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringAliasBindingMap.AddMappingToBoundKeyCache");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Command;
			*(ScriptArray<wchar_t>*)(params + 12) = MappingStr;
			*(int*)(params + 24) = FieldIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearBoundKeyCache()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringAliasBindingMap.ClearBoundKeyCache");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
