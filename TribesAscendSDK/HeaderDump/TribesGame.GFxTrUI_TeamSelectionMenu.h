#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "GFxUI.GFxObject.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.GameReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrUI_TeamSelectionMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrUI_TeamSelectionMenu." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrUI_TeamSelectionMenu : public GFxMoviePlayer
	{
	public:
		ADD_OBJECT(GFxObject, MovieClip)
		ADD_VAR(::BoolProperty, bCompleted, 0x4)
		ADD_OBJECT(GFxObject, DiamondSwordCountTF)
		ADD_OBJECT(GFxObject, BloodEagleCountTF)
		ADD_OBJECT(GFxObject, DiamondSwordButton)
		ADD_OBJECT(GFxObject, BloodEagleButton)
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_VAR(::BoolProperty, JoinDiamondSwordAllowed, 0x10)
		ADD_VAR(::BoolProperty, JoinBloodEagleAllowed, 0x8)
		ADD_VAR(::BoolProperty, bJustJoined, 0x2)
		ADD_VAR(::BoolProperty, bInitialized, 0x1)
		ADD_VAR(::IntProperty, PrevDiamondSwordCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevBloodEagleCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AllowedTeamDiscrepancyOnTeam, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AllowedTeamDiscrepancyNoTeam, 0xFFFFFFFF)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.Start");
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetFontIndex(int FontIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.SetFontIndex");
			byte* params = (byte*)malloc(4);
			*(int*)params = FontIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Show()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.Show");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLabels(ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Spectate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.SetLabels");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Title;
			*(ScriptArray<wchar_t>*)(params + 12) = Spectate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(class GameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.Tick");
			byte* params = (byte*)malloc(4);
			*(class GameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableBloodEagle(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableBloodEagle");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AsTeamChooseEnableButton(int TeamID, ScriptArray<wchar_t> bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.AsTeamChooseEnableButton");
			byte* params = (byte*)malloc(16);
			*(int*)params = TeamID;
			*(ScriptArray<wchar_t>*)(params + 4) = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableDiamondSword(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableDiamondSword");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableSpectate(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableSpectate");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bHaveTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
