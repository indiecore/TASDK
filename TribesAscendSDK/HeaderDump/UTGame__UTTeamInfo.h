#pragma once
#include "UTGame__UTTeamAI.h"
#include "Engine__TeamInfo.h"
#include "UTGame__UTBot.h"
#include "UTGame__UTGameObjective.h"
#include "UTGame__UTCarriedObject.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTTeamInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeamInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamInfo : public TeamInfo
	{
	public:
		ADD_VAR(::StrProperty, Faction, 0xFFFFFFFF)
		ADD_OBJECT(UTCarriedObject, TeamFlag)
		ADD_OBJECT(UTTeamAI, AI)
		ADD_OBJECT(UTGameObjective, HomeBase)
		ADD_VAR(::StrProperty, TeamColorNames, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BaseTeamColor'!
		ADD_VAR(::IntProperty, DesiredTeamSize, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetBotInfo'
		// Here lies the not-yet-implemented method 'AllBotsSpawned'
		// Here lies the not-yet-implemented method 'GetHUDColor'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'GetHumanReadableName'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'NeedsBotMoreThan'
		// Here lies the not-yet-implemented method 'SetBotOrders'
		// Here lies the not-yet-implemented method 'RemoveFromTeam'
		// Here lies the not-yet-implemented method 'BotNameTaken'
		// Here lies the not-yet-implemented method 'GetAvailableBotList'
		// Here lies the not-yet-implemented method 'Destroyed'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
