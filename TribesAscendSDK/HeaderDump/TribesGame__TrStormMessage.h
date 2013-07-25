#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStormMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrStormMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, FriendlyCoreDestroyed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyCore25Percent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyCore50Percent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyCore75Percent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyCoreDestroyed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyCore25Percent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyCore50Percent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyCore75Percent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyCarrierShieldsDown, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyCarrierShieldsDown, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyCarrierShields50Percent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyCarrierShields50Percent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ControlPointTransitioning, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ControlPointLost, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ControlPointWon, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormMessage.GetString");
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
