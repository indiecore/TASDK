#pragma once
#include "Engine__ReplicationInfo.h"
#include "Engine__Actor.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__TeamInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameReplicationInfo : public ReplicationInfo
	{
	public:
		ADD_OBJECT(ScriptClass, GameClass)
		ADD_VAR(::BoolProperty, bMatchHasBegun, 0x2)
		ADD_OBJECT(Actor, Winner)
		ADD_VAR(::StrProperty, ServerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemainingMinute, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bFriendlyFire, 0x8)
		ADD_VAR(::BoolProperty, bMatchIsOver, 0x4)
		ADD_VAR(::BoolProperty, bStopCountDown, 0x1)
		bool ShouldShowGore()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.ShouldShowGore");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceivedGameClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.ReceivedGameClass");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool OnSameTeam(class Actor* A, class Actor* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.OnSameTeam");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = A;
			*(class Actor**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddPRI(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.AddPRI");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemovePRI(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.RemovePRI");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTeam(int Index, class TeamInfo* TI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.SetTeam");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(class TeamInfo**)(params + 4) = TI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.StartMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.EndGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsMultiplayerGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.IsMultiplayerGame");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsCoopMultiplayerGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameReplicationInfo.IsCoopMultiplayerGame");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
