#pragma once
#include "Engine__ReplicationInfo.h"
#include "Engine__Actor.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__TeamInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameReplicationInfo : public ReplicationInfo
	{
	public:
		ADD_OBJECT(ScriptClass, GameClass)
		ADD_VAR(::BoolProperty, bMatchHasBegun, 0x2)
		ADD_OBJECT(Actor, Winner)
		ADD_VAR(::StrProperty, ServerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemainingMinute, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bFriendlyFire, 0x8)
		ADD_VAR(::BoolProperty, bMatchIsOver, 0x4)
		ADD_VAR(::BoolProperty, bStopCountDown, 0x1)
		// Here lies the not-yet-implemented method 'ShouldShowGore'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ReceivedGameClass'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'OnSameTeam'
		// Here lies the not-yet-implemented method 'AddPRI'
		// Here lies the not-yet-implemented method 'RemovePRI'
		// Here lies the not-yet-implemented method 'SetTeam'
		// Here lies the not-yet-implemented method 'StartMatch'
		// Here lies the not-yet-implemented method 'EndGame'
		// Here lies the not-yet-implemented method 'IsMultiplayerGame'
		// Here lies the not-yet-implemented method 'IsCoopMultiplayerGame'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
