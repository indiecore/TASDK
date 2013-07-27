#pragma once
#include "TribesGame.TrGame.h"
#include "TribesGame.TrPowerGenerator_Siege.h"
#include "Engine.PlayerReplicationInfo.h"
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
namespace UnrealScript
{
	class TrGame_TrSiege : public TrGame
	{
	public:
		ADD_STRUCT(ScriptArray<class TrPowerGenerator_Siege*>, m_Phase1OnlineGenerators, 1456)
		ADD_STRUCT(int, m_CurrentPhase, 1476)
		ADD_BOOL(m_bWasCoreDestroyedInRoundOne, 1472, 0x1)
		ADD_STRUCT(float, m_bRoundOneTimeSecs, 1468)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnGeneratorBlownUp(class TrPowerGenerator_Siege* G)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.OnGeneratorBlownUp");
			byte params[4] = { NULL };
			*(class TrPowerGenerator_Siege**)&params[0] = G;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCoreBlownUp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.OnCoreBlownUp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsInRoundOne()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.IsInRoundOne");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void RoundOneOver(bool bDestroyedCore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.RoundOneOver");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDestroyedCore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.ResetGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPhase(int PhaseNumber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.SetPhase");
			byte params[4] = { NULL };
			*(int*)&params[0] = PhaseNumber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwapTeams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.SwapTeams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrSiege.EndGame");
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
