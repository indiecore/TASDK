#pragma once
#include "Engine.UIDataStore_GameResource.h"
#include "Core.Object.h"
#include "UDKBase.UDKUIResourceDataProvider.h"
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
	class UDKUIDataStore_MenuItems : public UIDataStore_GameResource
	{
	public:
		ADD_STRUCT(ScriptArray<int>, EnabledMutators, 204)
		ADD_STRUCT(ScriptArray<int>, MapCycle, 216)
		ADD_STRUCT(ScriptArray<int>, WeaponPriority, 228)
		ADD_STRUCT(int, GameModeFilter, 240)
		ADD_OBJECT(ScriptClass, MapInfoDataProviderClass, 200)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 196)
		int GetProviderCount(ScriptName FieldName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.GetProviderCount");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool IsProviderFiltered(ScriptName FieldName, int ProviderIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.IsProviderFiltered");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = FieldName;
			*(int*)&params[8] = ProviderIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void GetAllResourceDataProviders(ScriptClass* ProviderClass, ScriptArray<class UDKUIResourceDataProvider*>& Providers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.GetAllResourceDataProviders");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = ProviderClass;
			*(ScriptArray<class UDKUIResourceDataProvider*>*)&params[4] = Providers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Providers = *(ScriptArray<class UDKUIResourceDataProvider*>*)&params[4];
		}
		int FindValueInProviderSet(ScriptName ProviderFieldName, ScriptName SearchTag, ScriptString* SearchValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.FindValueInProviderSet");
			byte params[32] = { NULL };
			*(ScriptName*)&params[0] = ProviderFieldName;
			*(ScriptName*)&params[8] = SearchTag;
			*(ScriptString**)&params[16] = SearchValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[28];
		}
		bool GetValueFromProviderSet(ScriptName ProviderFieldName, ScriptName SearchTag, int ListIndex, ScriptString*& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.GetValueFromProviderSet");
			byte params[36] = { NULL };
			*(ScriptName*)&params[0] = ProviderFieldName;
			*(ScriptName*)&params[8] = SearchTag;
			*(int*)&params[16] = ListIndex;
			*(ScriptString**)&params[20] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(ScriptString**)&params[20];
			return *(bool*)&params[32];
		}
		bool GetProviderSet(ScriptName ProviderFieldName, ScriptArray<class UDKUIResourceDataProvider*>& OutProviders)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.GetProviderSet");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ProviderFieldName;
			*(ScriptArray<class UDKUIResourceDataProvider*>*)&params[8] = OutProviders;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutProviders = *(ScriptArray<class UDKUIResourceDataProvider*>*)&params[8];
			return *(bool*)&params[20];
		}
		void InitializeListElementProviders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.InitializeListElementProviders");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveListElementProvidersKey(ScriptName KeyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.RemoveListElementProvidersKey");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = KeyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddListElementProvidersKey(ScriptName KeyName, class UDKUIResourceDataProvider* Provider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_MenuItems.AddListElementProvidersKey");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = KeyName;
			*(class UDKUIResourceDataProvider**)&params[8] = Provider;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
