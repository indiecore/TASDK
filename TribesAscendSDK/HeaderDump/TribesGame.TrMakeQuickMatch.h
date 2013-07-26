#pragma once
#include "TribesGame.TrGameSearchCommon.h"
#include "Core.Object.h"
#include "TribesGame.TrGameSettingsCommon.h"
#include "Engine.PlayerController.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchResult.h"
#include "Engine.LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrMakeQuickMatch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrMakeQuickMatch." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrMakeQuickMatch : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bProcessingJoin, 0x2)
		ADD_VAR(::BoolProperty, bIssuedInitialQuery, 0x1)
		ADD_OBJECT(TrGameSettingsCommon, GameSettings)
		ADD_OBJECT(TrGameSearchCommon, SearchSettings)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_VAR(::FloatProperty, SearchStarted, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ControllerId, 0xFFFFFFFF)
		bool Init(byte ControllerIndex, int GameMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.Init");
			byte* params = (byte*)malloc(9);
			*params = ControllerIndex;
			*(int*)(params + 4) = GameMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void Launch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.Launch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Cleanup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.Cleanup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SubmitGameSearch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.SubmitGameSearch");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class LocalPlayer* GetLP()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.GetLP");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class LocalPlayer**)params;
			free(params);
			return returnVal;
		}
		class PlayerController* GetPC()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.GetPC");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerController**)params;
			free(params);
			return returnVal;
		}
		void ConsoleCommand(ScriptArray<wchar_t> Cmd, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.ConsoleCommand");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Cmd;
			*(bool*)(params + 12) = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> BuildJoinURL(ScriptArray<wchar_t> ResolvedConnectionURL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.BuildJoinURL");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = ResolvedConnectionURL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		bool RequestJoin(OnlineGameSearchResult GameToJoin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.RequestJoin");
			byte* params = (byte*)malloc(12);
			*(OnlineGameSearchResult*)params = GameToJoin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void OnSearchComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.OnSearchComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnJoinGameComplete(ScriptName SessionName, bool bSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMakeQuickMatch.OnJoinGameComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
