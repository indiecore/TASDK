#pragma once
#include "Engine.Controller.h"
#include "UTGame.UTPickupFactory.h"
#include "Engine.SoundCue.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Pawn.h"
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
	class UTItemPickupFactory : public UTPickupFactory
	{
	public:
		ADD_STRUCT(ScriptString*, PickupMessage, 948)
		ADD_STRUCT(ScriptString*, UseHintMessage, 964)
		ADD_STRUCT(float, RespawnTime, 960)
		ADD_OBJECT(SoundCue, PickupSound, 944)
		void InitializePickup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40459);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetLocalString(int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40460);
			byte params[24] = { NULL };
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40465);
			byte params[4] = { NULL };
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRespawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40467);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetRespawnTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40468);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float BotDesireability(class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40470);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
