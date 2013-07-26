#pragma once
#include "Engine.UIDataStore_GameResource.h"
#include "Core.Object.Pointer.h"
#include "UDKBase.UDKUIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataStore_MenuItems." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataStore_MenuItems." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKUIDataStore_MenuItems." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKUIDataStore_MenuItems : public UIDataStore_GameResource
	{
	public:
		ADD_VAR(::IntProperty, GameModeFilter, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, MapInfoDataProviderClass)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementCellProvider, 0xFFFFFFFF)
		int GetProviderCount(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.GetProviderCount");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsProviderFiltered(ScriptName FieldName, int ProviderIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.IsProviderFiltered");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = FieldName;
			*(int*)(params + 8) = ProviderIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void GetAllResourceDataProviders(ScriptClass* ProviderClass, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Providers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.GetAllResourceDataProviders");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = ProviderClass;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Providers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Providers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		int FindValueInProviderSet(ScriptName ProviderFieldName, ScriptName SearchTag, ScriptArray<wchar_t> SearchValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.FindValueInProviderSet");
			byte* params = (byte*)malloc(32);
			*(ScriptName*)params = ProviderFieldName;
			*(ScriptName*)(params + 8) = SearchTag;
			*(ScriptArray<wchar_t>*)(params + 16) = SearchValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 28);
			free(params);
			return returnVal;
		}
		bool GetValueFromProviderSet(ScriptName ProviderFieldName, ScriptName SearchTag, int ListIndex, ScriptArray<wchar_t>& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.GetValueFromProviderSet");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = ProviderFieldName;
			*(ScriptName*)(params + 8) = SearchTag;
			*(int*)(params + 16) = ListIndex;
			*(ScriptArray<wchar_t>*)(params + 20) = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutValue = *(ScriptArray<wchar_t>*)(params + 20);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		bool GetProviderSet(ScriptName ProviderFieldName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutProviders)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.GetProviderSet");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ProviderFieldName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = OutProviders;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutProviders = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void InitializeListElementProviders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.InitializeListElementProviders");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveListElementProvidersKey(ScriptName KeyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.RemoveListElementProvidersKey");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = KeyName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddListElementProvidersKey(ScriptName KeyName, class UDKUIResourceDataProvider* Provider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.AddListElementProvidersKey");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = KeyName;
			*(class UDKUIResourceDataProvider**)(params + 8) = Provider;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
