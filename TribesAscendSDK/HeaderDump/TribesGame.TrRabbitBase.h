#pragma once
#include "UTGame.UTGameObjective.h"
#include "Engine.SoundNodeWave.h"
#include "UTGame.UTCarriedObject.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#include "TribesGame.TrFlagRabbit.h"
#include "Engine.MaterialInstanceConstant.h"
#include "UTGame.UTBot.h"
#include "Engine.Actor.h"
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "TribesGame.TrHelpTextManager.h"
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
	class TrRabbitBase : public UTGameObjective
	{
	public:
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, NearLocationSpeech, 1072)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, MidfieldHighSpeech, 1084)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, MidfieldLowSpeech, 1096)
		ADD_OBJECT(TrAnimNodeBlendList, m_OpenCloseBlendList, 1112)
		ADD_OBJECT(ScriptClass, CTFAnnouncerMessagesClass, 1068)
		ADD_OBJECT(MaterialInstanceConstant, MIC_FlagBaseColor, 1060)
		ADD_OBJECT(MaterialInstanceConstant, FlagBaseMaterial, 1056)
		ADD_STRUCT(float, BaseExitTime, 1048)
		ADD_STRUCT(float, NearBaseRadius, 1044)
		ADD_STRUCT(float, MidFieldLowZOffset, 1040)
		ADD_STRUCT(float, MidFieldHighZOffset, 1036)
		ADD_OBJECT(TrFlagRabbit, myFlag, 1032)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetBestViewTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.GetBestViewTarget");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		int GetLocationMessageIndex(class UTBot* B, class Pawn* StatusPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.GetLocationMessageIndex");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Pawn**)&params[4] = StatusPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		class SoundNodeWave* GetLocationSpeechFor(class PlayerController* PC, int LocationSpeechOffset, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.GetLocationSpeechFor");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(int*)&params[4] = LocationSpeechOffset;
			*(int*)&params[8] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		void ObjectiveChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.ObjectiveChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTCarriedObject* GetFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.GetFlag");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTCarriedObject**)&params[0];
		}
		bool IsActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.IsActive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnFlagComesHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.OnFlagComesHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFlagTaken()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.OnFlagTaken");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnHelpTextCollisionProxy(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitBase.SpawnHelpTextCollisionProxy");
			byte params[1] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
