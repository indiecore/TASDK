#pragma once
#include "TribesGame__TrFlagBase.h"
#include "UTGame__UTCarriedObject.h"
#include "TribesGame__TrGame.h"
#include "TribesGame__TrFlagCTF.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__AIController.h"
#include "Engine__Actor.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__PlayerController.h"
#include "UTGame__UTPlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TRCTF." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRCTF : public TrGame
	{
	public:
		ADD_OBJECT(TrFlagCTF, m_Flags)
		ADD_OBJECT(ScriptClass, AnnouncerMessageClass)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.GetHandicapNeed");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetLocationFor(class Pawn* StatusPawn, class Actor*& LocationObject, int& MessageIndex, int LocationSpeechOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.GetLocationFor");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = StatusPawn;
			*(class Actor**)(params + 4) = LocationObject;
			*(int*)(params + 8) = MessageIndex;
			*(int*)(params + 12) = LocationSpeechOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			LocationObject = *(class Actor**)(params + 4);
			MessageIndex = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void RegisterFlag(class UTCarriedObject* F, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.RegisterFlag");
			byte* params = (byte*)malloc(8);
			*(class UTCarriedObject**)params = F;
			*(int*)(params + 4) = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NearGoal(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.NearGoal");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool WantFastSpawnFor(class AIController* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.WantFastSpawnFor");
			byte* params = (byte*)malloc(8);
			*(class AIController**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ScoreFlag(class Controller* Scorer, class TrFlagBase* theFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.ScoreFlag");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Scorer;
			*(class TrFlagBase**)(params + 4) = theFlag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewObjective(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.ViewObjective");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Actor* GetAutoObjectiveFor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.GetAutoObjectiveFor");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		void AnnounceScore(int ScoringTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.AnnounceScore");
			byte* params = (byte*)malloc(4);
			*(int*)params = ScoringTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.GetGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
