#pragma once
#include "Engine__UIDataProvider.h"
#include "Engine__UIDataProvider_OnlineProfileSettings.h"
#include "Engine__UIResourceDataProvider.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIResourceCombinationProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIResourceCombinationProvider." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIResourceCombinationProvider : public UIDataProvider
	{
	public:
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider)
		ADD_OBJECT(UIResourceDataProvider, StaticDataProvider)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		void InitializeProvider(bool bIsEditor, class UIResourceDataProvider* InStaticResourceProvider, class UIDataProvider_OnlineProfileSettings* InProfileProvider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.InitializeProvider");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bIsEditor;
			*(class UIResourceDataProvider**)(params + 4) = InStaticResourceProvider;
			*(class UIDataProvider_OnlineProfileSettings**)(params + 8) = InProfileProvider;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GetElementProviderTags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementProviderTags");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		int GetElementCount(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementCount");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetListElements(ScriptName FieldName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Elements)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetListElements");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = FieldName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = out_Elements;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Elements = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool IsElementEnabled(ScriptName FieldName, int CollectionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.IsElementEnabled");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = CollectionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetElementCellSchemaProvider(ScriptName FieldName, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void*& out_SchemaProvider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementCellSchemaProvider");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = FieldName;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)(params + 8) = out_SchemaProvider;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_SchemaProvider = *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool GetElementCellValueProvider(ScriptName FieldName, int ListIndex, 
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void*& out_ValueProvider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementCellValueProvider");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = ListIndex;
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)(params + 12) = out_ValueProvider;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ValueProvider = *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void GetElementCellTags(ScriptName FieldName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& CellFieldTags, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ColumnHeaderDisplayText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetElementCellTags");
			byte* params = (byte*)malloc(32);
			*(ScriptName*)params = FieldName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = CellFieldTags;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = ColumnHeaderDisplayText;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CellFieldTags = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			ColumnHeaderDisplayText = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20);
			free(params);
		}
		bool GetCellFieldType(ScriptName FieldName, ScriptName CellTag, byte& FieldType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetCellFieldType");
			byte* params = (byte*)malloc(21);
			*(ScriptName*)params = FieldName;
			*(ScriptName*)(params + 8) = CellTag;
			*(params + 16) = FieldType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FieldType = *(params + 16);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetCellFieldValue(ScriptName FieldName, ScriptName CellTag, int ListIndex, 
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void*& out_FieldValue, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.GetCellFieldValue");
			byte* params = (byte*)malloc(116);
			*(ScriptName*)params = FieldName;
			*(ScriptName*)(params + 8) = CellTag;
			*(int*)(params + 16) = ListIndex;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void**)(params + 20) = out_FieldValue;
			*(int*)(params + 108) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_FieldValue = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void**)(params + 20);
			auto returnVal = *(bool*)(params + 112);
			free(params);
			return returnVal;
		}
		void ClearProviderReferences()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.ClearProviderReferences");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ReplaceProviderValue(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Fields, ScriptName TargetFieldTag, class UIDataProvider* ReplacementProvider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.ReplaceProviderValue");
			byte* params = (byte*)malloc(28);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_Fields;
			*(ScriptName*)(params + 12) = TargetFieldTag;
			*(class UIDataProvider**)(params + 20) = ReplacementProvider;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Fields = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool ReplaceProviderCollection(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Fields, ScriptName TargetFieldTag, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ReplacementProviders)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceCombinationProvider.ReplaceProviderCollection");
			byte* params = (byte*)malloc(36);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_Fields;
			*(ScriptName*)(params + 12) = TargetFieldTag;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = ReplacementProviders;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Fields = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			ReplacementProviders = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
