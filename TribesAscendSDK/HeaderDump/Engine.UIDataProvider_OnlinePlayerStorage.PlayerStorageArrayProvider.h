#pragma once
#include "Engine.UIDataProvider_OnlinePlayerStorageArray.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataProvider_OnlinePlayerStorage.PlayerStorageArrayProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UIDataProvider_OnlinePlayerStorage.PlayerStorageArrayProvider." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PlayerStorageArrayProvider
	{
	public:
		ADD_OBJECT(UIDataProvider_OnlinePlayerStorageArray, Provider)
		ADD_VAR(::NameProperty, PlayerStorageName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerStorageId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
