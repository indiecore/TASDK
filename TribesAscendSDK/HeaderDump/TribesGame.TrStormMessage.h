#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrStormMessage : public UTLocalMessage
	{
	public:
		ADD_STRUCT(ScriptString*, FriendlyCoreDestroyed, 268)
		ADD_STRUCT(ScriptString*, FriendlyCore25Percent, 256)
		ADD_STRUCT(ScriptString*, FriendlyCore50Percent, 244)
		ADD_STRUCT(ScriptString*, FriendlyCore75Percent, 232)
		ADD_STRUCT(ScriptString*, EnemyCoreDestroyed, 220)
		ADD_STRUCT(ScriptString*, EnemyCore25Percent, 208)
		ADD_STRUCT(ScriptString*, EnemyCore50Percent, 196)
		ADD_STRUCT(ScriptString*, EnemyCore75Percent, 184)
		ADD_STRUCT(ScriptString*, EnemyCarrierShieldsDown, 172)
		ADD_STRUCT(ScriptString*, FriendlyCarrierShieldsDown, 160)
		ADD_STRUCT(ScriptString*, EnemyCarrierShields50Percent, 148)
		ADD_STRUCT(ScriptString*, FriendlyCarrierShields50Percent, 136)
		ADD_STRUCT(ScriptString*, ControlPointTransitioning, 124)
		ADD_STRUCT(ScriptString*, ControlPointLost, 112)
		ADD_STRUCT(ScriptString*, ControlPointWon, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112919);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
	};
}
#undef ADD_STRUCT
