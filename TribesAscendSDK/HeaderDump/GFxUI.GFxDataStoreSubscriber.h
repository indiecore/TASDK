#pragma once
#include "Core.Object.h"
#include "GFxUI.GFxMoviePlayer.h"
#include "Core.Object.Pointer.h"
#include "Engine.UIDataStore.h"
#include "Engine.UIDataProvider.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxUI.GFxDataStoreSubscriber." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxUI.GFxDataStoreSubscriber." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxDataStoreSubscriber : public Object
	{
	public:
		ADD_OBJECT(GFxMoviePlayer, Movie)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIDataStorePublisher, 0xFFFFFFFF)
		void PublishValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxDataStoreSubscriber.PublishValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDataStoreBinding(ScriptArray<wchar_t> MarkupText, int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxDataStoreSubscriber.SetDataStoreBinding");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = MarkupText;
			*(int*)(params + 12) = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetDataStoreBinding(int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxDataStoreSubscriber.GetDataStoreBinding");
			byte* params = (byte*)malloc(16);
			*(int*)params = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool RefreshSubscriberValue(int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxDataStoreSubscriber.RefreshSubscriberValue");
			byte* params = (byte*)malloc(8);
			*(int*)params = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyDataStoreValueUpdated(class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxDataStoreSubscriber.NotifyDataStoreValueUpdated");
			byte* params = (byte*)malloc(24);
			*(class UIDataStore**)params = SourceDataStore;
			*(bool*)(params + 4) = bValuesInvalidated;
			*(ScriptName*)(params + 8) = PropertyTag;
			*(class UIDataProvider**)(params + 16) = SourceProvider;
			*(int*)(params + 20) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetBoundDataStores(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_BoundDataStores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxDataStoreSubscriber.GetBoundDataStores");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_BoundDataStores;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_BoundDataStores = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void ClearBoundDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxDataStoreSubscriber.ClearBoundDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SaveSubscriberValue(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_BoundDataStores, int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxDataStoreSubscriber.SaveSubscriberValue");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_BoundDataStores;
			*(int*)(params + 12) = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_BoundDataStores = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
