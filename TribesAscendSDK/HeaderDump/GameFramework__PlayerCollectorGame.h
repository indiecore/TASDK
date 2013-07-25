#pragma once
#include "Engine__GameInfo.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.PlayerCollectorGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerCollectorGame : public GameInfo
	{
	public:
		ADD_VAR(::StrProperty, URLToLoad, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumberOfClientsToWaitFor, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Login'
		// Here lies the not-yet-implemented method 'GetSeamlessTravelActorList'
	};
}
#undef ADD_VAR
