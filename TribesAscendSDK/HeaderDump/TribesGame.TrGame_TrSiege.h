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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90864);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnGeneratorBlownUp(class TrPowerGenerator_Siege* G)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90866);
			byte params[4] = { NULL };
			*(class TrPowerGenerator_Siege**)params = G;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCoreBlownUp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90868);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsInRoundOne()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90869);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RoundOneOver(bool bDestroyedCore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90871);
			byte params[4] = { NULL };
			*(bool*)params = bDestroyedCore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90876);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPhase(int PhaseNumber)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90878);
			byte params[4] = { NULL };
			*(int*)params = PhaseNumber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwapTeams()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90881);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90887);
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
