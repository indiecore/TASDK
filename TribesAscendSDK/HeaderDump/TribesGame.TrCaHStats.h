#pragma once
#include "Core.Object.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.GfxTrHud.h"
#include "TribesGame.TrGameReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCaHStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCaHStats." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCaHStats : public Object
	{
	public:
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::IntProperty, RoundNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumCapturePointsHeld, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoundScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamScore, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceUpdateNextTick, 0x4)
		ADD_VAR(::BoolProperty, bForcingUpdate, 0x2)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MyTeam, 0xFFFFFFFF)
		void ReadyToPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.ReadyToPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.Initialize");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)(params + 4) = MP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Show()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.Show");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.Hide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.Tick");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.UpdateTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCapturePointData(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.UpdateCapturePointData");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTeamScore(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.UpdateTeamScore");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.FormatTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void ForceUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCaHStats.ForceUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
