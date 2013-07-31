#pragma once
#include "Engine.UIRoot.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider : public UIRoot
	{
	public:
		enum EProviderAccessType : byte
		{
			ACCESS_ReadOnly = 0,
			ACCESS_PerField = 1,
			ACCESS_WriteAll = 2,
			ACCESS_MAX = 3,
		};
		struct UIDataProviderField
		{
		public:
			ADD_STRUCT(ScriptArray<class UIDataProvider*>, FieldProviders, 12)
			ADD_STRUCT(UIRoot::EUIDataProviderFieldType, FieldType, 8)
			ADD_STRUCT(ScriptName, FieldTag, 0)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, ProviderChangedNotifies, 64)
		ADD_STRUCT(UIDataProvider::EProviderAccessType, WriteAccessType, 60)
		void OnDataProviderPropertyChange(class UIDataProvider* SourceProvider, ScriptName PropTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22531);
			byte params[12] = { NULL };
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)&params[4] = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetProviderFieldType(ScriptString* DataTag, UIRoot::EUIDataProviderFieldType& out_ProviderFieldType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22536);
			byte params[17] = { NULL };
			*(ScriptString**)params = DataTag;
			*(UIRoot::EUIDataProviderFieldType*)&params[12] = out_ProviderFieldType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ProviderFieldType = *(UIRoot::EUIDataProviderFieldType*)&params[12];
			return *(bool*)&params[16];
		}
		int ParseArrayDelimiter(ScriptString*& DataTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22540);
			byte params[16] = { NULL };
			*(ScriptString**)params = DataTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DataTag = *(ScriptString**)params;
			return *(int*)&params[12];
		}
		void GetSupportedScriptFields(ScriptArray<UIDataProvider::UIDataProviderField>& out_Fields)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22543);
			byte params[12] = { NULL };
			*(ScriptArray<UIDataProvider::UIDataProviderField>*)params = out_Fields;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Fields = *(ScriptArray<UIDataProvider::UIDataProviderField>*)params;
		}
		bool AllowPublishingToField(ScriptString* FieldName, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22546);
			byte params[20] = { NULL };
			*(ScriptString**)params = FieldName;
			*(int*)&params[12] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool GetFieldValue(ScriptString* FieldName, UIRoot::UIProviderScriptFieldValue& FieldValue, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22550);
			byte params[104] = { NULL };
			*(ScriptString**)params = FieldName;
			*(UIRoot::UIProviderScriptFieldValue*)&params[12] = FieldValue;
			*(int*)&params[96] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FieldValue = *(UIRoot::UIProviderScriptFieldValue*)&params[12];
			return *(bool*)&params[100];
		}
		bool SetFieldValue(ScriptString* FieldName, UIRoot::UIProviderScriptFieldValue& FieldValue, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22555);
			byte params[104] = { NULL };
			*(ScriptString**)params = FieldName;
			*(UIRoot::UIProviderScriptFieldValue*)&params[12] = FieldValue;
			*(int*)&params[96] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FieldValue = *(UIRoot::UIProviderScriptFieldValue*)&params[12];
			return *(bool*)&params[100];
		}
		ScriptString* GenerateScriptMarkupString(ScriptName DataTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22560);
			byte params[20] = { NULL };
			*(ScriptName*)params = DataTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		ScriptString* GenerateFillerData(ScriptString* DataTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22563);
			byte params[24] = { NULL };
			*(ScriptString**)params = DataTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		bool IsProviderDisabled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22566);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsCollectionDataType(UIRoot::EUIDataProviderFieldType FieldType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22568);
			byte params[5] = { NULL };
			*(UIRoot::EUIDataProviderFieldType*)params = FieldType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyPropertyChanged(ScriptName PropTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22571);
			byte params[8] = { NULL };
			*(ScriptName*)params = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AddPropertyNotificationChangeRequest(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate, bool bAllowDuplicates)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22577);
			byte params[20] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			*(bool*)&params[12] = bAllowDuplicates;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool RemovePropertyNotificationChangeRequest(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22583);
			byte params[16] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int ParseTagArrayDelimiter(ScriptName& FieldName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22588);
			byte params[12] = { NULL };
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FieldName = *(ScriptName*)params;
			return *(int*)&params[8];
		}
	};
}
#undef ADD_STRUCT
