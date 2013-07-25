#pragma once
#include "Engine__OnlineSubsystem.h"
#include "IpDrv__OnlineGameInterfaceImpl.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineSubsystemCommonImpl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.OnlineSubsystemCommonImpl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.OnlineSubsystemCommonImpl." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystemCommonImpl : public OnlineSubsystem
	{
	public:
		ADD_OBJECT(OnlineGameInterfaceImpl, GameInterfaceImpl)
		ADD_VAR(::BoolProperty, bIsUsingSpeechRecognition, 0x1)
		ADD_VAR(::IntProperty, MaxRemoteTalkers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLocalTalkers, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VoiceEngine'!
		// Here lies the not-yet-implemented method 'GetPlayerNicknameFromIndex'
		// Here lies the not-yet-implemented method 'GetPlayerUniqueNetIdFromIndex'
		// Here lies the not-yet-implemented method 'IsPlayerInSession'
		// Here lies the not-yet-implemented method 'GetRegisteredPlayers'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
