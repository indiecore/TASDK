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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.Init");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* InitMessageRow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.InitMessageRow");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[0];
		}
		void ClearStats(bool clearScores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.ClearStats");
			byte params[4] = { NULL };
			*(bool*)&params[0] = clearScores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameHUD(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.UpdateGameHUD");
			byte params[4] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetRank(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.GetRank");
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_OBJECT
