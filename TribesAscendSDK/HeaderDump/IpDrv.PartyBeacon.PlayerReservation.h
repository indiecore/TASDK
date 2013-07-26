#pragma once
#include "Core.Object.Double.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PartyBeacon.PlayerReservation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PartyBeacon.PlayerReservation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerReservation
	{
	public:
		ADD_VAR(::FloatProperty, ElapsedSessionTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Double>, Sigma, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Double>, Mu, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, XpLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Skill, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, NetId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
