#pragma once
#include "Engine.UIRoot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider : public UIRoot
	{
	public:
		ADD_VAR(::ByteProperty, WriteAccessType, 0xFFFFFFFF)
		void OnDataProviderPropertyChange(class UIDataProvider* SourceProvider, ScriptName PropTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.OnDataProviderPropertyChange");
			byte* params = (byte*)malloc(12);
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)(params + 4) = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetProviderFieldType(ScriptArray<wchar_t> DataTag, byte& out_ProviderFieldType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.GetProviderFieldType");
			byte* params = (byte*)malloc(17);
			*(ScriptArray<wchar_t>*)params = DataTag;
			*(params + 12) = out_ProviderFieldType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ProviderFieldType = *(params + 12);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		int ParseArrayDelimiter(ScriptArray<wchar_t>& DataTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.ParseArrayDelimiter");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = DataTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DataTag = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void GetSupportedScriptFields(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Fields)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.GetSupportedScriptFields");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_Fields;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Fields = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		bool AllowPublishingToField(ScriptArray<wchar_t> FieldName, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.AllowPublishingToField");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = FieldName;
			*(int*)(params + 12) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool GetFieldValue(ScriptArray<wchar_t> FieldName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void*& FieldValue, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.GetFieldValue");
			byte* params = (byte*)malloc(104);
			*(ScriptArray<wchar_t>*)params = FieldName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void**)(params + 12) = FieldValue;
			*(int*)(params + 96) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FieldValue = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 100);
			free(params);
			return returnVal;
		}
		bool SetFieldValue(ScriptArray<wchar_t> FieldName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void*& FieldValue, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.SetFieldValue");
			byte* params = (byte*)malloc(104);
			*(ScriptArray<wchar_t>*)params = FieldName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void**)(params + 12) = FieldValue;
			*(int*)(params + 96) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FieldValue = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 100);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GenerateScriptMarkupString(ScriptName DataTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.GenerateScriptMarkupString");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = DataTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GenerateFillerData(ScriptArray<wchar_t> DataTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.GenerateFillerData");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = DataTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		bool IsProviderDisabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.IsProviderDisabled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsCollectionDataType(byte FieldType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.IsCollectionDataType");
			byte* params = (byte*)malloc(5);
			*params = FieldType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyPropertyChanged(ScriptName PropTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.NotifyPropertyChanged");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AddPropertyNotificationChangeRequest(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate, bool bAllowDuplicates)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.AddPropertyNotificationChangeRequest");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			*(bool*)(params + 12) = bAllowDuplicates;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool RemovePropertyNotificationChangeRequest(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.RemovePropertyNotificationChangeRequest");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		int ParseTagArrayDelimiter(ScriptName& FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider.ParseTagArrayDelimiter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FieldName = *(ScriptName*)params;
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
