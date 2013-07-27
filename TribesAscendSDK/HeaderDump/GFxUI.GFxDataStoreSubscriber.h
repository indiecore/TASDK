#pragma once
#include "Core.Object.h"
#include "GFxUI.GFxMoviePlayer.h"
#include "Engine.UIDataStore.h"
#include "Engine.UIDataProvider.h"
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
	class GFxDataStoreSubscriber : public Object
	{
	public:
		ADD_OBJECT(GFxMoviePlayer, Movie, 64)
		ADD_STRUCT(Object::Pointer, VfTable_IUIDataStorePublisher, 60)
		void PublishValues()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30255);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDataStoreBinding(ScriptString* MarkupText, int BindingIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30256);
			byte params[16] = { NULL };
			*(ScriptString**)params = MarkupText;
			*(int*)&params[12] = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDataStoreBinding(int BindingIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30259);
			byte params[16] = { NULL };
			*(int*)params = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool RefreshSubscriberValue(int BindingIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30262);
			byte params[8] = { NULL };
			*(int*)params = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyDataStoreValueUpdated(class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30265);
			byte params[24] = { NULL };
			*(class UIDataStore**)params = SourceDataStore;
			*(bool*)&params[4] = bValuesInvalidated;
			*(ScriptName*)&params[8] = PropertyTag;
			*(class UIDataProvider**)&params[16] = SourceProvider;
			*(int*)&params[20] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetBoundDataStores(ScriptArray<class UIDataStore*>& out_BoundDataStores)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30271);
			byte params[12] = { NULL };
			*(ScriptArray<class UIDataStore*>*)params = out_BoundDataStores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_BoundDataStores = *(ScriptArray<class UIDataStore*>*)params;
		}
		void ClearBoundDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30274);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SaveSubscriberValue(ScriptArray<class UIDataStore*>& out_BoundDataStores, int BindingIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30275);
			byte params[20] = { NULL };
			*(ScriptArray<class UIDataStore*>*)params = out_BoundDataStores;
			*(int*)&params[12] = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_BoundDataStores = *(ScriptArray<class UIDataStore*>*)params;
			return *(bool*)&params[16];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
