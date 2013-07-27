#pragma once
#include "Engine.UIDataProvider.h"
#include "Engine.UIRoot.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDynamicFieldProvider : public UIDataProvider
	{
	public:
		ADD_STRUCT(ScriptArray<UIRoot::UIProviderScriptFieldValue>, PersistentDataFields, 88)
		ADD_STRUCT(ScriptArray<UIRoot::UIProviderScriptFieldValue>, RuntimeDataFields, 100)
		ADD_STRUCT(Object::Map_Mirror, RuntimeCollectionData, 172)
		ADD_STRUCT(Object::Map_Mirror, PersistentCollectionData, 112)
		void InitializeRuntimeFields()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.InitializeRuntimeFields");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AddField(ScriptName FieldName, UIRoot::EUIDataProviderFieldType FieldType, bool bPersistent, int& out_InsertPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.AddField");
			byte params[21] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(UIRoot::EUIDataProviderFieldType*)&params[8] = FieldType;
			*(bool*)&params[12] = bPersistent;
			*(int*)&params[16] = out_InsertPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_InsertPosition = *(int*)&params[16];
			return *(bool*)&params[20];
		}
		bool RemoveField(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.RemoveField");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int FindFieldIndex(ScriptName FieldName, bool bSearchPersistentFields)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.FindFieldIndex");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(bool*)&params[8] = bSearchPersistentFields;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool ClearFields(bool bReinitializeRuntimeFields)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.ClearFields");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bReinitializeRuntimeFields;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetField(ScriptName FieldName, UIRoot::UIProviderScriptFieldValue& out_Field)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.GetField");
			byte params[96] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(UIRoot::UIProviderScriptFieldValue*)&params[8] = out_Field;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Field = *(UIRoot::UIProviderScriptFieldValue*)&params[8];
			return *(bool*)&params[92];
		}
		bool SetField(ScriptName FieldName, UIRoot::UIProviderScriptFieldValue& FieldValue, bool bChangeExistingOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.SetField");
			byte params[100] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(UIRoot::UIProviderScriptFieldValue*)&params[8] = FieldValue;
			*(bool*)&params[92] = bChangeExistingOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FieldValue = *(UIRoot::UIProviderScriptFieldValue*)&params[8];
			return *(bool*)&params[96];
		}
		void SavePersistentProviderData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.SavePersistentProviderData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetCollectionValueSchema(ScriptName FieldName, ScriptArray<ScriptName>& out_CellTagArray, bool bPersistent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.GetCollectionValueSchema");
			byte params[28] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptArray<ScriptName>*)&params[8] = out_CellTagArray;
			*(bool*)&params[20] = bPersistent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CellTagArray = *(ScriptArray<ScriptName>*)&params[8];
			return *(bool*)&params[24];
		}
		bool GetCollectionValueArray(ScriptName FieldName, ScriptArray<ScriptString*>& out_DataValueArray, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.GetCollectionValueArray");
			byte params[36] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptArray<ScriptString*>*)&params[8] = out_DataValueArray;
			*(bool*)&params[20] = bPersistent;
			*(ScriptName*)&params[24] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_DataValueArray = *(ScriptArray<ScriptString*>*)&params[8];
			return *(bool*)&params[32];
		}
		bool SetCollectionValueArray(ScriptName FieldName, ScriptArray<ScriptString*>& CollectionValues, bool bClearExisting, int InsertIndex, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.SetCollectionValueArray");
			byte params[44] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptArray<ScriptString*>*)&params[8] = CollectionValues;
			*(bool*)&params[20] = bClearExisting;
			*(int*)&params[24] = InsertIndex;
			*(bool*)&params[28] = bPersistent;
			*(ScriptName*)&params[32] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CollectionValues = *(ScriptArray<ScriptString*>*)&params[8];
			return *(bool*)&params[40];
		}
		bool InsertCollectionValue(ScriptName FieldName, ScriptString*& NewValue, int InsertIndex, bool bPersistent, bool bAllowDuplicateValues, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.InsertCollectionValue");
			byte params[44] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptString**)&params[8] = NewValue;
			*(int*)&params[20] = InsertIndex;
			*(bool*)&params[24] = bPersistent;
			*(bool*)&params[28] = bAllowDuplicateValues;
			*(ScriptName*)&params[32] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[8];
			return *(bool*)&params[40];
		}
		bool RemoveCollectionValue(ScriptName FieldName, ScriptString*& ValueToRemove, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.RemoveCollectionValue");
			byte params[36] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptString**)&params[8] = ValueToRemove;
			*(bool*)&params[20] = bPersistent;
			*(ScriptName*)&params[24] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueToRemove = *(ScriptString**)&params[8];
			return *(bool*)&params[32];
		}
		bool RemoveCollectionValueByIndex(ScriptName FieldName, int ValueIndex, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.RemoveCollectionValueByIndex");
			byte params[28] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(int*)&params[8] = ValueIndex;
			*(bool*)&params[12] = bPersistent;
			*(ScriptName*)&params[16] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool ReplaceCollectionValue(ScriptName FieldName, ScriptString*& CurrentValue, ScriptString*& NewValue, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.ReplaceCollectionValue");
			byte params[48] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptString**)&params[8] = CurrentValue;
			*(ScriptString**)&params[20] = NewValue;
			*(bool*)&params[32] = bPersistent;
			*(ScriptName*)&params[36] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CurrentValue = *(ScriptString**)&params[8];
			NewValue = *(ScriptString**)&params[20];
			return *(bool*)&params[44];
		}
		bool ReplaceCollectionValueByIndex(ScriptName FieldName, int ValueIndex, ScriptString*& NewValue, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.ReplaceCollectionValueByIndex");
			byte params[40] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(int*)&params[8] = ValueIndex;
			*(ScriptString**)&params[12] = NewValue;
			*(bool*)&params[24] = bPersistent;
			*(ScriptName*)&params[28] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[12];
			return *(bool*)&params[36];
		}
		bool ClearCollectionValueArray(ScriptName FieldName, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.ClearCollectionValueArray");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(bool*)&params[8] = bPersistent;
			*(ScriptName*)&params[12] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool GetCollectionValue(ScriptName FieldName, int ValueIndex, ScriptString*& out_Value, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.GetCollectionValue");
			byte params[40] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(int*)&params[8] = ValueIndex;
			*(ScriptString**)&params[12] = out_Value;
			*(bool*)&params[24] = bPersistent;
			*(ScriptName*)&params[28] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Value = *(ScriptString**)&params[12];
			return *(bool*)&params[36];
		}
		int FindCollectionValueIndex(ScriptName FieldName, ScriptString*& ValueToFind, bool bPersistent, ScriptName CellTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicFieldProvider.FindCollectionValueIndex");
			byte params[36] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(ScriptString**)&params[8] = ValueToFind;
			*(bool*)&params[20] = bPersistent;
			*(ScriptName*)&params[24] = CellTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueToFind = *(ScriptString**)&params[8];
			return *(int*)&params[32];
		}
	};
}
#undef ADD_STRUCT
