#pragma once
#include "UTGame.UTGameObjective.h"
#include "Engine.SoundNodeWave.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.MaterialInstanceConstant.h"
#include "UTGame.UTBot.h"
#include "Engine.Actor.h"
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
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
	class UTCTFBase : public UTGameObjective
	{
	public:
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, NearLocationSpeech, 1076)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, MidfieldHighSpeech, 1088)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, MidfieldLowSpeech, 1100)
		ADD_OBJECT(ScriptClass, CTFAnnouncerMessagesClass, 1072)
		ADD_OBJECT(MaterialInstanceConstant, MIC_FlagBaseColor, 1064)
		ADD_OBJECT(MaterialInstanceConstant, FlagBaseMaterial, 1060)
		ADD_STRUCT(float, BaseExitTime, 1052)
		ADD_STRUCT(float, NearBaseRadius, 1048)
		ADD_STRUCT(float, MidFieldLowZOffset, 1044)
		ADD_STRUCT(float, MidFieldHighZOffset, 1040)
		ADD_OBJECT(ScriptClass, FlagType, 1036)
		ADD_OBJECT(UTCarriedObject, myFlag, 1032)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetBestViewTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.GetBestViewTarget");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		int GetLocationMessageIndex(class UTBot* B, class Pawn* StatusPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.GetLocationMessageIndex");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Pawn**)&params[4] = StatusPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		class SoundNodeWave* GetLocationSpeechFor(class PlayerController* PC, int LocationSpeechOffset, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.GetLocationSpeechFor");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(int*)&params[4] = LocationSpeechOffset;
			*(int*)&params[8] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		void ObjectiveChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.ObjectiveChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTCarriedObject* GetFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.GetFlag");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTCarriedObject**)&params[0];
		}
		void SetAlarm(bool bNowOn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.SetAlarm");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowOn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.IsActive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
