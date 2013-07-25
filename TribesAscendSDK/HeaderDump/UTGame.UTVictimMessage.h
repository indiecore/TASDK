#pragma once
#include "Core.Object.h"
#include "UTGame.UTWeaponKillMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVictimMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTVictimMessage : public UTWeaponKillMessage
	{
	public:
		ADD_VAR(::StrProperty, TelefragString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ViperKamikazeString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScorpionKamikazeString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SpiderMineString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RunOverString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OrbSuicideString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KilledByTrailer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouWereKilledBy, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVictimMessage.GetString");
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
