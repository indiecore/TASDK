#pragma once
#include "Core__Object.h"
#include "GFxUI__GFxMoviePlayer.h"
#include "Engine__UIDataStore.h"
#include "Engine__UIDataProvider.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIDataStorePublisher'!
		// Here lies the not-yet-implemented method 'PublishValues'
		// Here lies the not-yet-implemented method 'SetDataStoreBinding'
		// Here lies the not-yet-implemented method 'GetDataStoreBinding'
		// Here lies the not-yet-implemented method 'RefreshSubscriberValue'
		// Here lies the not-yet-implemented method 'NotifyDataStoreValueUpdated'
		// Here lies the not-yet-implemented method 'GetBoundDataStores'
		// Here lies the not-yet-implemented method 'ClearBoundDataStores'
		// Here lies the not-yet-implemented method 'SaveSubscriberValue'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
