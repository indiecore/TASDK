#pragma once
#include "IpDrv__OnlineGameInterfaceImpl.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineGameInterfaceMcts : public OnlineGameInterfaceImpl
	{
	public:
		ADD_OBJECT(OnlineGameSearch, InviteGameSearch)
		ADD_OBJECT(OnlineVoiceInterfaceMcts, MctsVoiceInt)
		ADD_OBJECT(MctsOnlineSettings, MctsSettings)
	};
}
#undef ADD_OBJECT
