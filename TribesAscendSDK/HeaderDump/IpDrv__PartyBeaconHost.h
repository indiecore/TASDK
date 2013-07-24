#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.PartyBeaconHost." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PartyBeaconHost : public PartyBeacon
	{
	public:
		ADD_VAR(::ByteProperty, BeaconState, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBestFitTeamAssignment, 0x1)
		ADD_VAR(::IntProperty, ReservedHostTeamNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ForceTeamNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConnectionBacklog, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, OnlineSessionName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumConsumedReservations, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumReservations, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumPlayersPerTeam, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumTeams, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
