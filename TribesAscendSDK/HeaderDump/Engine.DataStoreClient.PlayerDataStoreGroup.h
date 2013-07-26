#pragma once
#include "Engine.LocalPlayer.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty DataStoreClient.PlayerDataStoreGroup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PlayerDataStoreGroup
	{
	public:
		ADD_OBJECT(LocalPlayer, PlayerOwner)
	};
}
#undef ADD_OBJECT
