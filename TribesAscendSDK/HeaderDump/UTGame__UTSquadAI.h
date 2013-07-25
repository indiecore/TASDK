#pragma once
#include "UDKBase__UDKSquadAI.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSquadAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSquadAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSquadAI : public UDKSquadAI
	{
	public:
		ADD_OBJECT(Controller, SquadLeader)
		ADD_OBJECT(UTBot, SquadMembers)
		ADD_VAR(::FloatProperty, FormationSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShouldUseGatherPoints, 0x20)
		ADD_VAR(::BoolProperty, bAddTransientCosts, 0x10)
		ADD_VAR(::BoolProperty, bRoamingSquad, 0x8)
		ADD_VAR(::BoolProperty, bFreelanceDefend, 0x4)
		ADD_VAR(::BoolProperty, bFreelanceAttack, 0x2)
		ADD_VAR(::BoolProperty, bFreelance, 0x1)
		ADD_VAR(::IntProperty, MaxSquadSize, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, Enemies)
		ADD_VAR(::NameProperty, CurrentOrders, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SupportStringTrailer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FreelanceString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HoldString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AttackString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefendString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SupportString, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Size, 0xFFFFFFFF)
		ADD_OBJECT(UTSquadAI, NextSquad)
		ADD_OBJECT(UTPlayerReplicationInfo, LeaderPRI)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
