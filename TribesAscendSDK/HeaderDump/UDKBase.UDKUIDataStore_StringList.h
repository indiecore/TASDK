#pragma once
#include "Engine.UIDataStore_StringBase.h"
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
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
	class UDKUIDataStore_StringList : public UIDataStore_StringBase
	{
	public:
		static const auto INVALIDFIELD = -1;
		struct EStringListData
		{
		public:
			ADD_STRUCT(ScriptArray<ScriptString*>, Strings, 36)
			ADD_OBJECT(UDKUIDataProvider_StringArray, DataProvider, 48)
			ADD_STRUCT(int, DefaultValueIndex, 32)
			ADD_STRUCT(ScriptString*, CurrentValue, 20)
			ADD_STRUCT(ScriptString*, ColumnHeaderText, 8)
			ADD_STRUCT(ScriptName, Tag, 0)
		};
		ADD_STRUCT(ScriptArray<UDKUIDataStore_StringList::EStringListData>, StringData, 128)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 124)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementProvider, 120)
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35705);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetFieldIndex(ScriptName FieldName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35708);
			byte params[12] = { NULL };
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void AddStr(ScriptName FieldName, ScriptString* NewString, bool bBatchOp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35711);
			byte params[24] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptString**)&params[8] = NewString;
			*(bool*)&params[20] = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InsertStr(ScriptName FieldName, ScriptString* NewString, int InsertIndex, bool bBatchOp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35715);
			byte params[28] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptString**)&params[8] = NewString;
			*(int*)&params[20] = InsertIndex;
			*(bool*)&params[24] = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveStr(ScriptName FieldName, ScriptString* StringToRemove, bool bBatchOp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35720);
			byte params[24] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptString**)&params[8] = StringToRemove;
			*(bool*)&params[20] = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveStrByIndex(ScriptName FieldName, int Index, int Count, bool bBatchOp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35724);
			byte params[20] = { NULL };
			*(ScriptName*)params = FieldName;
			*(int*)&params[8] = Index;
			*(int*)&params[12] = Count;
			*(bool*)&params[16] = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Empty(ScriptName FieldName, bool bBatchOp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35729);
			byte params[12] = { NULL };
			*(ScriptName*)params = FieldName;
			*(bool*)&params[8] = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int FindStr(ScriptName FieldName, ScriptString* SearchString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35732);
			byte params[24] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptString**)&params[8] = SearchString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		ScriptString* GetStr(ScriptName FieldName, int StrIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35736);
			byte params[24] = { NULL };
			*(ScriptName*)params = FieldName;
			*(int*)&params[8] = StrIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptArray<ScriptString*> GetList(ScriptName FieldName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35740);
			byte params[20] = { NULL };
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<ScriptString*>*)&params[8];
		}
		bool GetCurrentValue(ScriptName FieldName, ScriptString*& out_Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35744);
			byte params[24] = { NULL };
			*(ScriptName*)params = FieldName;
			*(ScriptString**)&params[8] = out_Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Value = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		int GetCurrentValueIndex(ScriptName FieldName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35750);
			byte params[12] = { NULL };
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int SetCurrentValueIndex(ScriptName FieldName, int NewValueIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35755);
			byte params[16] = { NULL };
			*(ScriptName*)params = FieldName;
			*(int*)&params[8] = NewValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int Num(ScriptName FieldName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35761);
			byte params[12] = { NULL };
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
