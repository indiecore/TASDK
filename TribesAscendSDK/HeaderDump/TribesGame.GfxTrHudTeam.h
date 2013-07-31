#pragma once
#include "TribesGame.GfxTrHud.h"
#include "GFxUI.GFxObject.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.LocalPlayer.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GfxTrHudTeam : public GfxTrHud
	{
	public:
		ADD_OBJECT(GFxObject, FlagCarrierTF, 3132)
		ADD_OBJECT(GFxObject, ScoreTF, 3124)
		ADD_OBJECT(GFxObject, ScoreBarMC, 3116)
		void Init(class LocalPlayer* Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54270);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* InitMessageRow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54272);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)params;
		}
		void ClearStats(bool clearScores)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54274);
			byte params[4] = { NULL };
			*(bool*)params = clearScores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameHUD(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54277);
			byte params[4] = { NULL };
			*(class UTPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetRank(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54284);
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_OBJECT
