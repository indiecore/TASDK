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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.InitializeProvider");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bIsEditor;
			*(class UIResourceDataProvider**)&params[4] = InStaticResourceProvider;
			*(class UIDataProvider_OnlineProfileSettings**)&params[8] = InProfileProvider;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptArray<ScriptName> GetElementProviderTags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementProviderTags");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<ScriptName>*)&params[0];
		}
		int GetElementCount(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementCount");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool GetListElements(ScriptName FieldName, ScriptArray<int>& out_Elements)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetListElements");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptArray<int>*)&params[8] = out_Elements;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Elements = *(ScriptArray<int>*)&params[8];
			return *(bool*)&params[20];
		}
		bool IsElementEnabled(ScriptName FieldName, int CollectionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.IsElementEnabled");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(int*)&params[8] = CollectionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GetElementCellSchemaProvider(ScriptName FieldName, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void*& out_SchemaProvider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementCellSchemaProvider");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementCellValueProvider");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementCellTags");
			byte params[32] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptArray<ScriptName>*)&params[8] = CellFieldTags;
			*(ScriptArray<ScriptString*>*)&params[20] = ColumnHeaderDisplayText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CellFieldTags = *(ScriptArray<ScriptName>*)&params[8];
			ColumnHeaderDisplayText = *(ScriptArray<ScriptString*>*)&params[20];
		}
		bool GetCellFieldType(ScriptName FieldName, ScriptName CellTag, UIRoot::EUIDataProviderFieldType& FieldType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetCellFieldType");
			byte params[21] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptName*)&params[8] = CellTag;
			*(UIRoot::EUIDataProviderFieldType*)&params[16] = FieldType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FieldType = *(UIRoot::EUIDataProviderFieldType*)&params[16];
			return *(bool*)&params[20];
		}
		bool GetCellFieldValue(ScriptName FieldName, ScriptName CellTag, int ListIndex, UIRoot::UIProviderFieldValue& out_FieldValue, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetCellFieldValue");
			byte params[116] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.ClearProviderReferences");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReplaceProviderValue(ScriptArray<UIDataProvider::UIDataProviderField>& out_Fields, ScriptName TargetFieldTag, class UIDataProvider* ReplacementProvider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.ReplaceProviderValue");
			byte params[28] = { NULL };
			*(ScriptArray<UIDataProvider::UIDataProviderField>*)&params[0] = out_Fields;
			*(ScriptName*)&params[12] = TargetFieldTag;
			*(class UIDataProvider**)&params[20] = ReplacementProvider;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Fields = *(ScriptArray<UIDataProvider::UIDataProviderField>*)&params[0];
			return *(bool*)&params[24];
		}
		bool ReplaceProviderCollection(ScriptArray<UIDataProvider::UIDataProviderField>& out_Fields, ScriptName TargetFieldTag, ScriptArray<class UIDataProvider*>& ReplacementProviders)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.ReplaceProviderCollection");
			byte params[36] = { NULL };
			*(ScriptArray<UIDataProvider::UIDataProviderField>*)&params[0] = out_Fields;
			*(ScriptName*)&params[12] = TargetFieldTag;
			*(ScriptArray<class UIDataProvider*>*)&params[20] = ReplacementProviders;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Fields = *(ScriptArray<UIDataProvider::UIDataProviderField>*)&params[0];
			ReplacementProviders = *(ScriptArray<class UIDataProvider*>*)&params[20];
			return *(bool*)&params[32];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
