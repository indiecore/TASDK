#pragma once
#include "Engine__LocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameMessage : public LocalMessage
	{
	public:
		ADD_VAR(::StrProperty, MaxedOutMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SpecEnteredMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NewSpecMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KickWarning, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NewPlayerMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BecameSpectator, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CantBePlayer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CantBeSpectator, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MustHaveStats, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VotePassed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VoteStarted, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NoNameChange, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NewTeamMessageTrailer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NewTeamMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GlobalNameChange, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OvertimeMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ArbitrationMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnteredMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FailedSpawnMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FailedPlaceMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FailedTeamMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LeftMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SwitchLevelMessage, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameMessage.GetString");
			byte* params = (byte*)malloc(32);
			*(int*)params = Switch;
			*(bool*)(params + 4) = bPRI1HUD;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
