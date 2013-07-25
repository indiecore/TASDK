#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrWarningMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrWarningMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, RequiresPowerToFire, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RequiresCreditsToFire, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SuicidePenalty, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MissileIntercepted, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MissileTargetingYou, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MissileLockedOnToYou, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SaberLauncherNeedsTargetToFire, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FumbledFlag, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrWarningMessage.GetString");
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
