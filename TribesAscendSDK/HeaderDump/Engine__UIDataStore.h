#pragma once
#include "Engine__UIDataProvider.h"
#include "Engine__DataStoreClient.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStore : public UIDataProvider
	{
	public:
		ADD_VAR(::NameProperty, Tag, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'NotifyGameSessionEnded'
		// Here lies the not-yet-implemented method 'OnDataStoreValueUpdated'
		// Here lies the not-yet-implemented method 'Registered'
		// Here lies the not-yet-implemented method 'Unregistered'
		// Here lies the not-yet-implemented method 'SubscriberAttached'
		// Here lies the not-yet-implemented method 'SubscriberDetached'
		// Here lies the not-yet-implemented method 'RefreshSubscribers'
		// Here lies the not-yet-implemented method 'OnCommit'
		// Here lies the not-yet-implemented method 'GetDataStoreClient'
	};
}
#undef ADD_VAR
