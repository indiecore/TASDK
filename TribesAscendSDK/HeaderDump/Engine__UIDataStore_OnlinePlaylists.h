#pragma once
#include "Engine__UIDataStore.h"
#include "Engine__UIResourceDataProvider.h"
#include "Engine__OnlinePlaylistProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlinePlaylists." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_OnlinePlaylists." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_OnlinePlaylists." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlinePlaylists : public UIDataStore
	{
	public:
		ADD_OBJECT(ScriptClass, ProviderClass)
		ADD_VAR(::StrProperty, ProviderClassName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		// Here lies the not-yet-implemented method 'GetProviderCount'
		// Here lies the not-yet-implemented method 'GetResourceProviders'
		// Here lies the not-yet-implemented method 'GetResourceProviderFields'
		// Here lies the not-yet-implemented method 'GetProviderFieldValue'
		// Here lies the not-yet-implemented method 'FindProviderIndexByFieldValue'
		// Here lies the not-yet-implemented method 'GetPlaylistProvider'
		// Here lies the not-yet-implemented method 'GetOnlinePlaylistProvider'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
