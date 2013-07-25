#pragma once
#include "Core.Object.h"
#include "TribesGame.GfxTrHud.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrGameReplicationInfo.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHUDTeamCTFStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrHUDTeamCTFStats." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrHUDTeamCTFStats : public Object
	{
	public:
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_OBJECT(PlayerReplicationInfo, FlagHolderPRI)
		ADD_VAR(::ByteProperty, bEmptyFlagStatus, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FlagState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GeneratorDowntime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GeneratorPower, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FlagReturnTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MyTeam, 0xFFFFFFFF)
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.Initialize");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)(params + 4) = MP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Show()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.Show");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.Hide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.Tick");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.UpdateTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetTeamIndex(int I)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.GetTeamIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = I;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateFlagStatus(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.UpdateFlagStatus");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGeneratorStatus(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.UpdateGeneratorStatus");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTeamScore(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.UpdateTeamScore");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTime(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.UpdateTime");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.FormatTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void ForceUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDTeamCTFStats.ForceUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
