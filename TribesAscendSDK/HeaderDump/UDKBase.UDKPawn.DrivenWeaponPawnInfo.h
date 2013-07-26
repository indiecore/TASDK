#pragma once
#include "UDKBase.UDKVehicle.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKPawn.DrivenWeaponPawnInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKPawn.DrivenWeaponPawnInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DrivenWeaponPawnInfo
	{
	public:
		ADD_OBJECT(PlayerReplicationInfo, PRI)
		ADD_VAR(::ByteProperty, SeatIndex, 0xFFFFFFFF)
		ADD_OBJECT(UDKVehicle, BaseVehicle)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
