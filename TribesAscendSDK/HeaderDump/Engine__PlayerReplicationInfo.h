#pragma once
#include "Engine__ReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PlayerReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PlayerReplicationInfo : public ReplicationInfo
	{
	public:
		ADD_VAR(::BoolProperty, bAdmin, 0x1)
		ADD_VAR(::StrProperty, PlayerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerID, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId' for the property named 'UniqueId'!
		ADD_VAR(::BoolProperty, bOnlySpectator, 0x4)
		ADD_OBJECT(TeamInfo, Team)
		ADD_VAR(::NameProperty, SessionName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExactPing, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Ping, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsSpectator, 0x2)
		ADD_VAR(::BoolProperty, bReadyToPlay, 0x10)
		ADD_VAR(::BoolProperty, bOutOfLives, 0x20)
		ADD_VAR(::FloatProperty, Score, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PlayerReplicationInfo.AutomatedTestingDatum' for the property named 'AutomatedTestingData'!
		ADD_VAR(::IntProperty, StartTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SavedNetworkAddress, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingPlayer, 0x8)
		ADD_VAR(::IntProperty, Kills, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFromPreviousLevel, 0x200)
		ADD_VAR(::BoolProperty, bIsInactive, 0x100)
		ADD_VAR(::StrProperty, OldName, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, Avatar)
		ADD_VAR(::IntProperty, StatAvgOutBPS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatMaxOutBPS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatAvgInBPS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatMaxInBPS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPKLMax, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPKLMin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPKLTotal, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPingMax, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPingMin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPingTotals, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatConnectionCounts, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StringUnknown, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StringSpectating, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasBeenWelcomed, 0x80)
		ADD_VAR(::BoolProperty, bBot, 0x40)
		ADD_VAR(::IntProperty, NumLives, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TTSSpeaker, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Deaths, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
