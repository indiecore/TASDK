#pragma once
#include "Engine.UIRoot.UIProviderScriptFieldValue.h"
#include "Engine.UIDataProvider.h"
#include "Core.Object.Map_Mirror.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDynamicFieldProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDynamicFieldProvider : public UIDataProvider
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Map_Mirror>, RuntimeCollectionData, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Map_Mirror>, PersistentCollectionData, 0xFFFFFFFF)
		void InitializeRuntimeFields()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.InitializeRuntimeFields");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AddField(ScriptName FieldName, byte FieldType, bool bPersistent, int& out_InsertPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.AddField");
			byte* params = (byte*)malloc(21);
			*(ScriptName*)params = FieldName;
			*(params + 8) = FieldType;
			*(bool*)(params + 12) = bPersistent;
			*(int*)(params + 16) = out_InsertPosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_InsertPosition = *(int*)(params + 16);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool RemoveField(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.RemoveField");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int FindFieldIndex(ScriptName FieldName, bool bSearchPersistentFields)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.FindFieldIndex");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = FieldName;
			*(bool*)(params + 8) = bSearchPersistentFields;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ClearFields(bool bReinitializeRuntimeFields)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.ClearFields");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bReinitializeRuntimeFields;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetField(ScriptName FieldName, UIProviderScriptFieldValue& out_Field)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.GetField");
			byte* params = (byte*)malloc(96);
			*(ScriptName*)params = FieldName;
			*(UIProviderScriptFieldValue*)(params + 8) = out_Field;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Field = *(UIProviderScriptFieldValue*)(params + 8);
			auto returnVal = *(bool*)(params + 92);
			free(params);
			return returnVal;
		}
		bool SetField(ScriptName FieldName, UIProviderScriptFieldValue& FieldValue, bool bChangeExistingOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.SetField");
			byte* params = (byte*)malloc(100);
			*(ScriptName*)params = FieldName;
			*(UIProviderScriptFieldValue*)(params + 8) = FieldValue;
			*(bool*)(params + 92) = bChangeExistingOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FieldValue = *(UIProviderScriptFieldValue*)(params + 8);
			auto returnVal = *(bool*)(params + 96);
			free(params);
			return returnVal;
		}
		void SavePersistentProviderData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.SavePersistentProviderData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetCollectionValueSchema(ScriptName FieldName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_CellTagArray, bool bPersistent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.GetCollectionValueSchema");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = FieldName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = out_CellTagArray;
			*(bool*)(params + 20) = bPersistent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CellTagArray = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool GetCollectionValueArray(ScriptName FieldName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_DataValueArray, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.GetCollectionValueArray");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = FieldName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = out_DataValueArray;
			*(bool*)(params + 20) = bPersistent;
			*(ScriptName*)(params + 24) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_DataValueArray = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		bool SetCollectionValueArray(ScriptName FieldName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& CollectionValues, bool bClearExisting, int InsertIndex, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.SetCollectionValueArray");
			byte* params = (byte*)malloc(44);
			*(ScriptName*)params = FieldName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = CollectionValues;
			*(bool*)(params + 20) = bClearExisting;
			*(int*)(params + 24) = InsertIndex;
			*(bool*)(params + 28) = bPersistent;
			*(ScriptName*)(params + 32) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CollectionValues = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 40);
			free(params);
			return returnVal;
		}
		bool InsertCollectionValue(ScriptName FieldName, ScriptArray<wchar_t>& NewValue, int InsertIndex, bool bPersistent, bool bAllowDuplicateValues, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.InsertCollectionValue");
			byte* params = (byte*)malloc(44);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = NewValue;
			*(int*)(params + 20) = InsertIndex;
			*(bool*)(params + 24) = bPersistent;
			*(bool*)(params + 28) = bAllowDuplicateValues;
			*(ScriptName*)(params + 32) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewValue = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 40);
			free(params);
			return returnVal;
		}
		bool RemoveCollectionValue(ScriptName FieldName, ScriptArray<wchar_t>& ValueToRemove, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.RemoveCollectionValue");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = ValueToRemove;
			*(bool*)(params + 20) = bPersistent;
			*(ScriptName*)(params + 24) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ValueToRemove = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		bool RemoveCollectionValueByIndex(ScriptName FieldName, int ValueIndex, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.RemoveCollectionValueByIndex");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = ValueIndex;
			*(bool*)(params + 12) = bPersistent;
			*(ScriptName*)(params + 16) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool ReplaceCollectionValue(ScriptName FieldName, ScriptArray<wchar_t>& CurrentValue, ScriptArray<wchar_t>& NewValue, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.ReplaceCollectionValue");
			byte* params = (byte*)malloc(48);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = CurrentValue;
			*(ScriptArray<wchar_t>*)(params + 20) = NewValue;
			*(bool*)(params + 32) = bPersistent;
			*(ScriptName*)(params + 36) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CurrentValue = *(ScriptArray<wchar_t>*)(params + 8);
			NewValue = *(ScriptArray<wchar_t>*)(params + 20);
			auto returnVal = *(bool*)(params + 44);
			free(params);
			return returnVal;
		}
		bool ReplaceCollectionValueByIndex(ScriptName FieldName, int ValueIndex, ScriptArray<wchar_t>& NewValue, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.ReplaceCollectionValueByIndex");
			byte* params = (byte*)malloc(40);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = ValueIndex;
			*(ScriptArray<wchar_t>*)(params + 12) = NewValue;
			*(bool*)(params + 24) = bPersistent;
			*(ScriptName*)(params + 28) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewValue = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		bool ClearCollectionValueArray(ScriptName FieldName, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.ClearCollectionValueArray");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = FieldName;
			*(bool*)(params + 8) = bPersistent;
			*(ScriptName*)(params + 12) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetCollectionValue(ScriptName FieldName, int ValueIndex, ScriptArray<wchar_t>& out_Value, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.GetCollectionValue");
			byte* params = (byte*)malloc(40);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = ValueIndex;
			*(ScriptArray<wchar_t>*)(params + 12) = out_Value;
			*(bool*)(params + 24) = bPersistent;
			*(ScriptName*)(params + 28) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Value = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		int FindCollectionValueIndex(ScriptName FieldName, ScriptArray<wchar_t>& ValueToFind, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.FindCollectionValueIndex");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = ValueToFind;
			*(bool*)(params + 20) = bPersistent;
			*(ScriptName*)(params + 24) = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ValueToFind = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(int*)(params + 32);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
