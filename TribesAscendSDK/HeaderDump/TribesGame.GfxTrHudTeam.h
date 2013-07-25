#pragma once
#include "TribesGame.GfxTrHud.h"
#include "GFxUI.GFxObject.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.LocalPlayer.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GfxTrHudTeam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GfxTrHudTeam : public GfxTrHud
	{
	public:
		ADD_OBJECT(GFxObject, FlagCarrierTF)
		ADD_OBJECT(GFxObject, ScoreTF)
		ADD_OBJECT(GFxObject, ScoreBarMC)
		void Init(class LocalPlayer* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.Init");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* InitMessageRow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.InitMessageRow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		void ClearStats(bool clearScores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.ClearStats");
			byte* params = (byte*)malloc(4);
			*(bool*)params = clearScores;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGameHUD(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.UpdateGameHUD");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetRank(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHudTeam.GetRank");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
