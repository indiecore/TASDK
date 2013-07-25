#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineGameInterfaceImpl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.OnlineGameInterfaceImpl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.OnlineGameInterfaceImpl." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineGameInterfaceImpl : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SessionInfo'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'LanBeacon'!
		ADD_VAR(::FloatProperty, LanQueryTimeout, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LanQueryTimeLeft, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LanPacketPlatformMask, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LanGameUniqueId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LanAnnouncePort, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LanNonce, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LanBeaconState, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentGameState, 0xFFFFFFFF)
		ADD_OBJECT(OnlineGameSearch, GameSearch)
		ADD_OBJECT(OnlineGameSettings, GameSettings)
		ADD_OBJECT(OnlineSubsystemCommonImpl, OwningSubsystem)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
