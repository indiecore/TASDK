#pragma once
#include "Engine.UIDataProvider.h"
#include "Engine.UIDataProvider_OnlineProfileSettings.h"
#include "Engine.UIResourceDataProvider.h"
#include "Core.Object.h"
#include "Engine.UIRoot.h"
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
	class UIResourceCombinationProvider : public UIDataProvider
	{
	public:
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider, 100)
		ADD_OBJECT(UIResourceDataProvider, StaticDataProvider, 96)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 92)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementProvider, 88)
		void InitializeProvider(bool bIsEditor, class UIResourceDataProvider* InStaticResourceProvider, class UIDataProvider_OnlineProfileSettings* InProfileProvider)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29150);
			byte params[12] = { NULL };
			*(bool*)params = bIsEditor;
			*(class UIResourceDataProvider**)&params[4] = InStaticResourceProvider;
			*(class UIDataProvider_OnlineProfileSettings**)&params[8] = InProfileProvider;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptArray<ScriptName> GetElementProviderTags()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29154);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<ScriptName>*)params;
		}
		int GetElementCount(ScriptName FieldName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29159);
			byte params[12] = { NULL };
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool GetListElements(ScriptName FieldName, ScriptArray<int>& out_Elements)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29163);
			byte params[24] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptArray<int>*)&params[8] = out_Elements;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Elements = *(ScriptArray<int>*)&params[8];
			return *(bool*)&params[20];
		}
		bool IsElementEnabled(ScriptName FieldName, int CollectionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29169);
			byte params[16] = { NULL };
			*(ScriptName*)params = FieldName;
			*(int*)&params[8] = CollectionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GetElementCellSchemaProvider(ScriptName FieldName, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void*& out_SchemaProvider)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29174);
			byte params[20] = { NULL };
			*(ScriptName*)params = FieldName;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[8] = out_SchemaProvider;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_SchemaProvider = *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[8];
			return *(bool*)&params[16];
		}
		bool GetElementCellValueProvider(ScriptName FieldName, int ListIndex, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void*& out_ValueProvider)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29179);
			byte params[24] = { NULL };
			*(ScriptName*)params = FieldName;
			*(int*)&params[8] = ListIndex;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[12] = out_ValueProvider;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ValueProvider = *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[12];
			return *(bool*)&params[20];
		}
		void GetElementCellTags(ScriptName FieldName, ScriptArray<ScriptName>& CellFieldTags, ScriptArray<ScriptString*>& ColumnHeaderDisplayText)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29185);
			byte params[32] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptArray<ScriptName>*)&params[8] = CellFieldTags;
			*(ScriptArray<ScriptString*>*)&params[20] = ColumnHeaderDisplayText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CellFieldTags = *(ScriptArray<ScriptName>*)&params[8];
			ColumnHeaderDisplayText = *(ScriptArray<ScriptString*>*)&params[20];
		}
		bool GetCellFieldType(ScriptName FieldName, ScriptName CellTag, UIRoot::EUIDataProviderFieldType& FieldType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29191);
			byte params[21] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptName*)&params[8] = CellTag;
			*(UIRoot::EUIDataProviderFieldType*)&params[16] = FieldType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FieldType = *(UIRoot::EUIDataProviderFieldType*)&params[16];
			return *(bool*)&params[20];
		}
		bool GetCellFieldValue(ScriptName FieldName, ScriptName CellTag, int ListIndex, UIRoot::UIProviderFieldValue& out_FieldValue, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29197);
			byte params[116] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptName*)&params[8] = CellTag;
			*(int*)&params[16] = ListIndex;
			*(UIRoot::UIProviderFieldValue*)&params[20] = out_FieldValue;
			*(int*)&params[108] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_FieldValue = *(UIRoot::UIProviderFieldValue*)&params[20];
			return *(bool*)&params[112];
		}
		void ClearProviderReferences()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29205);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReplaceProviderValue(ScriptArray<UIDataProvider::UIDataProviderField>& out_Fields, ScriptName TargetFieldTag, class UIDataProvider* ReplacementProvider)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29206);
			byte params[28] = { NULL };
			*(ScriptArray<UIDataProvider::UIDataProviderField>*)params = out_Fields;
			*(ScriptName*)&params[12] = TargetFieldTag;
			*(class UIDataProvider**)&params[20] = ReplacementProvider;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Fields = *(ScriptArray<UIDataProvider::UIDataProviderField>*)params;
			return *(bool*)&params[24];
		}
		bool ReplaceProviderCollection(ScriptArray<UIDataProvider::UIDataProviderField>& out_Fields, ScriptName TargetFieldTag, ScriptArray<class UIDataProvider*>& ReplacementProviders)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29214);
			byte params[36] = { NULL };
			*(ScriptArray<UIDataProvider::UIDataProviderField>*)params = out_Fields;
			*(ScriptName*)&params[12] = TargetFieldTag;
			*(ScriptArray<class UIDataProvider*>*)&params[20] = ReplacementProviders;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Fields = *(ScriptArray<UIDataProvider::UIDataProviderField>*)params;
			ReplacementProviders = *(ScriptArray<class UIDataProvider*>*)&params[20];
			return *(bool*)&params[32];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
