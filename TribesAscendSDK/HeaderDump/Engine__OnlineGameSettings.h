#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineGameSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineGameSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineGameSettings : public Settings
	{
	public:
		ADD_VAR(::BoolProperty, bUsesArbitration, 0x100)
		ADD_VAR(::IntProperty, NumOpenPrivateConnections, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumOpenPublicConnections, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, GameState, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId' for the property named 'OwningPlayerId'!
		ADD_VAR(::BoolProperty, bIsLanMatch, 0x2)
		ADD_VAR(::BoolProperty, bUsesStats, 0x4)
		ADD_VAR(::IntProperty, NumPublicConnections, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BuildUniqueId, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MatchQuality, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PingInMs, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OwningPlayerName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasSkillUpdateInProgress, 0x1000)
		ADD_VAR(::BoolProperty, bIsDedicated, 0x800)
		ADD_VAR(::BoolProperty, bWasFromInvite, 0x400)
		ADD_VAR(::BoolProperty, bAntiCheatProtected, 0x200)
		ADD_VAR(::BoolProperty, bAllowJoinViaPresenceFriendsOnly, 0x80)
		ADD_VAR(::BoolProperty, bAllowJoinViaPresence, 0x40)
		ADD_VAR(::BoolProperty, bUsesPresence, 0x20)
		ADD_VAR(::BoolProperty, bAllowInvites, 0x10)
		ADD_VAR(::BoolProperty, bAllowJoinInProgress, 0x8)
		ADD_VAR(::BoolProperty, bShouldAdvertise, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.QWord' for the property named 'ServerNonce'!
		ADD_VAR(::IntProperty, NumPrivateConnections, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
