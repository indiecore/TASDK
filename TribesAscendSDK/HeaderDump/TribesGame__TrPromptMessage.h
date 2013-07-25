#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPromptMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPromptMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPromptMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, YourJackalGrenadesHaveBeenDestroyed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnterVehicle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ObjectiveUpgradeDeniedMaxLevel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ObjectiveUpgradeDeniedNoCredits, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KickWarning, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UpgradeObjective, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EquipRepairGun, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, UpgradeDeniedSound)
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPromptMessage.GetString");
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
		ScriptArray<wchar_t> FormatText(ScriptArray<wchar_t> InString, class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPromptMessage.FormatText");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = InString;
			*(class TrPlayerController**)(params + 12) = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
