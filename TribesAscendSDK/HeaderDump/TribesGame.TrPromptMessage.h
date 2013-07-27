#pragma once
#include "UTGame.UTLocalMessage.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.SoundCue.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrPromptMessage : public UTLocalMessage
	{
	public:
		ADD_STRUCT(ScriptString*, YourJackalGrenadesHaveBeenDestroyed, 176)
		ADD_STRUCT(ScriptString*, EnterVehicle, 164)
		ADD_STRUCT(ScriptString*, ObjectiveUpgradeDeniedMaxLevel, 152)
		ADD_STRUCT(ScriptString*, ObjectiveUpgradeDeniedNoCredits, 140)
		ADD_STRUCT(ScriptString*, KickWarning, 128)
		ADD_STRUCT(ScriptString*, UpgradeObjective, 116)
		ADD_STRUCT(ScriptString*, EquipRepairGun, 104)
		ADD_OBJECT(SoundCue, UpgradeDeniedSound, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPromptMessage.GetString");
			byte params[32] = { NULL };
			*(int*)&params[0] = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		ScriptString* FormatText(ScriptString* InString, class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPromptMessage.FormatText");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = InString;
			*(class TrPlayerController**)&params[12] = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
