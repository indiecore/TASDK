#pragma once
#include "UTGame.UTGameObjective.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.MaterialInstanceConstant.h"
#include "UTGame.UTBot.h"
#include "Engine.Actor.h"
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "Engine.SoundNodeWave.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFBase : public UTGameObjective
	{
	public:
		ADD_OBJECT(ScriptClass, CTFAnnouncerMessagesClass)
		ADD_OBJECT(MaterialInstanceConstant, MIC_FlagBaseColor)
		ADD_OBJECT(MaterialInstanceConstant, FlagBaseMaterial)
		ADD_VAR(::FloatProperty, BaseExitTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NearBaseRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidFieldLowZOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidFieldHighZOffset, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, FlagType)
		ADD_OBJECT(UTCarriedObject, myFlag)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetBestViewTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.GetBestViewTarget");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		int GetLocationMessageIndex(class UTBot* B, class Pawn* StatusPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.GetLocationMessageIndex");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Pawn**)(params + 4) = StatusPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		class SoundNodeWave* GetLocationSpeechFor(class PlayerController* PC, int LocationSpeechOffset, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.GetLocationSpeechFor");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			*(int*)(params + 4) = LocationSpeechOffset;
			*(int*)(params + 8) = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundNodeWave**)(params + 12);
			free(params);
			return returnVal;
		}
		void ObjectiveChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.ObjectiveChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTCarriedObject* GetFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.GetFlag");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTCarriedObject**)params;
			free(params);
			return returnVal;
		}
		void SetAlarm(bool bNowOn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.SetAlarm");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowOn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFBase.IsActive");
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
