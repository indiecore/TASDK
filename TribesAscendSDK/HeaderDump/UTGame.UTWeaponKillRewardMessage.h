#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.SoundNodeWave.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#include "Engine.PlayerController.h"
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
	class UTWeaponKillRewardMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, RewardSounds, 124)
		ADD_STRUCT(ScriptString*, RewardString, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50182);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50189);
			byte params[20] = { NULL };
			*(class PlayerController**)params = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50195);
			byte params[16] = { NULL };
			*(int*)params = MessageIndex;
			*(class Object**)&params[4] = OptionalObject;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
