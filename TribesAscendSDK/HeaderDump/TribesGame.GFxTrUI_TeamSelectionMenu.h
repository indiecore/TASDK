#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "GFxUI.GFxObject.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.GameReplicationInfo.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class GFxTrUI_TeamSelectionMenu : public GFxMoviePlayer
	{
	public:
		ADD_OBJECT(GFxObject, MovieClip, 404)
		ADD_BOOL(bCompleted, 396, 0x4)
		ADD_OBJECT(GFxObject, DiamondSwordCountTF, 420)
		ADD_OBJECT(GFxObject, BloodEagleCountTF, 416)
		ADD_OBJECT(GFxObject, DiamondSwordButton, 412)
		ADD_OBJECT(GFxObject, BloodEagleButton, 408)
		ADD_OBJECT(TrPlayerController, TrPC, 400)
		ADD_BOOL(JoinDiamondSwordAllowed, 396, 0x10)
		ADD_BOOL(JoinBloodEagleAllowed, 396, 0x8)
		ADD_BOOL(bJustJoined, 396, 0x2)
		ADD_BOOL(bInitialized, 396, 0x1)
		ADD_STRUCT(int, PrevDiamondSwordCount, 392)
		ADD_STRUCT(int, PrevBloodEagleCount, 388)
		ADD_STRUCT(int, AllowedTeamDiscrepancyOnTeam, 384)
		ADD_STRUCT(int, AllowedTeamDiscrepancyNoTeam, 380)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.Start");
			byte params[8] = { NULL };
			*(bool*)&params[0] = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetFontIndex(int FontIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.SetFontIndex");
			byte params[4] = { NULL };
			*(int*)&params[0] = FontIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Show()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.Show");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLabels(ScriptString* Title, ScriptString* Spectate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.SetLabels");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Title;
			*(ScriptString**)&params[12] = Spectate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(class GameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.Tick");
			byte params[4] = { NULL };
			*(class GameReplicationInfo**)&params[0] = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableBloodEagle(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableBloodEagle");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AsTeamChooseEnableButton(int TeamID, ScriptString* bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.AsTeamChooseEnableButton");
			byte params[16] = { NULL };
			*(int*)&params[0] = TeamID;
			*(ScriptString**)&params[4] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableDiamondSword(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableDiamondSword");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableSpectate(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableSpectate");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void choseTeamBE()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.choseTeamBE");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void choseTeamDS()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.choseTeamDS");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void choseTeamSpectate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.choseTeamSpectate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompleteMovie(bool bHaveTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.CompleteMovie");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bHaveTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
