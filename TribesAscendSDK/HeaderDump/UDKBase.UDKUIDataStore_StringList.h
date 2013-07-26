#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.UIDataStore_StringBase.h"
#include "Engine.LocalPlayer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataStore_StringList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_StringList : public UIDataStore_StringBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementCellProvider, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementProvider, 0xFFFFFFFF)
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.Registered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetFieldIndex(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.GetFieldIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddStr(ScriptName FieldName, ScriptArray<wchar_t> NewString, bool bBatchOp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.AddStr");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = NewString;
			*(bool*)(params + 20) = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InsertStr(ScriptName FieldName, ScriptArray<wchar_t> NewString, int InsertIndex, bool bBatchOp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.InsertStr");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = NewString;
			*(int*)(params + 20) = InsertIndex;
			*(bool*)(params + 24) = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveStr(ScriptName FieldName, ScriptArray<wchar_t> StringToRemove, bool bBatchOp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.RemoveStr");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = StringToRemove;
			*(bool*)(params + 20) = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveStrByIndex(ScriptName FieldName, int Index, int Count, bool bBatchOp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.RemoveStrByIndex");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = Index;
			*(int*)(params + 12) = Count;
			*(bool*)(params + 16) = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Empty(ScriptName FieldName, bool bBatchOp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.Empty");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = FieldName;
			*(bool*)(params + 8) = bBatchOp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int FindStr(ScriptName FieldName, ScriptArray<wchar_t> SearchString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.FindStr");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = SearchString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetStr(ScriptName FieldName, int StrIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.GetStr");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = StrIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GetList(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.GetList");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetCurrentValue(ScriptName FieldName, ScriptArray<wchar_t>& out_Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.GetCurrentValue");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 8) = out_Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Value = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		int GetCurrentValueIndex(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.GetCurrentValueIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int SetCurrentValueIndex(ScriptName FieldName, int NewValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.SetCurrentValueIndex");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = NewValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int Num(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringList.Num");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
