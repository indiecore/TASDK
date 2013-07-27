#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.SoundCue.h"
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
	class TrMiscellaneousMessage : public UTLocalMessage
	{
	public:
		ADD_STRUCT(ScriptString*, EnemyTeamBoughtHerc, 144)
		ADD_STRUCT(ScriptString*, OurTeamBoughtHerc, 132)
		ADD_OBJECT(SoundCue, DiamondSwordCloseToLoss, 128)
		ADD_OBJECT(SoundCue, DiamondSwordCloseToWin, 124)
		ADD_OBJECT(SoundCue, BloodEagleCloseToLoss, 120)
		ADD_OBJECT(SoundCue, BloodEagleCloseToWin, 116)
		ADD_OBJECT(SoundCue, FriendDiamondSwordBoughtHerc, 112)
		ADD_OBJECT(SoundCue, FriendBloodEagleBoughtHerc, 108)
		ADD_OBJECT(SoundCue, EnemyDiamondSwordBoughtHerc, 104)
		ADD_OBJECT(SoundCue, EnemyBloodEagleBoughtHerc, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMiscellaneousMessage.GetString");
			byte params[32] = { NULL };
			*(int*)&params[0] = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMiscellaneousMessage.ClientReceive");
			byte params[20] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
