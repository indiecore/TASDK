#pragma once
#include "TribesGame.TrGame.h"
#include "TribesGame.TrPowerGenerator_Siege.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrSiege." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrSiege : public TrGame
	{
	public:
		ADD_VAR(::IntProperty, m_CurrentPhase, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bWasCoreDestroyedInRoundOne, 0x1)
		ADD_VAR(::FloatProperty, m_bRoundOneTimeSecs, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnGeneratorBlownUp(class TrPowerGenerator_Siege* G)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.OnGeneratorBlownUp");
			byte* params = (byte*)malloc(4);
			*(class TrPowerGenerator_Siege**)params = G;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnCoreBlownUp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.OnCoreBlownUp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsInRoundOne()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.IsInRoundOne");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RoundOneOver(bool bDestroyedCore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.RoundOneOver");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDestroyedCore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.ResetGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPhase(int PhaseNumber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.SetPhase");
			byte* params = (byte*)malloc(4);
			*(int*)params = PhaseNumber;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwapTeams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.SwapTeams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.EndGame");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
