#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "TribesGame__GfxTrHud.h"
#include "Core__Object.h"
#include "TribesGame__TrGameReplicationInfo.h"
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHUDTeamCTFStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrHUDTeamCTFStats." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrHUDTeamCTFStats : public Object
	{
	public:
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_OBJECT(PlayerReplicationInfo, FlagHolderPRI)
		ADD_VAR(::ByteProperty, bEmptyFlagStatus, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FlagState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GeneratorDowntime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GeneratorPower, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FlagReturnTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MyTeam, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'Show'
		// Here lies the not-yet-implemented method 'Hide'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'UpdateTeam'
		// Here lies the not-yet-implemented method 'GetTeamIndex'
		// Here lies the not-yet-implemented method 'UpdateFlagStatus'
		// Here lies the not-yet-implemented method 'UpdateGeneratorStatus'
		// Here lies the not-yet-implemented method 'UpdateTeamScore'
		// Here lies the not-yet-implemented method 'UpdateTime'
		// Here lies the not-yet-implemented method 'FormatTime'
		// Here lies the not-yet-implemented method 'ForceUpdate'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
