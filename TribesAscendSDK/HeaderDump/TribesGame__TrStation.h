#pragma once
#include "TribesGame__TrCaHCapturePoint.h"
#include "TribesGame__TrGameObjective.h"
#include "TribesGame__TrStationCollision.h"
#include "Engine__SoundCue.h"
#include "TribesGame__TrPawn.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrStation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrStation : public TrGameObjective
	{
	public:
		ADD_OBJECT(TrCaHCapturePoint, m_OwningCaHCapturePoint)
		ADD_OBJECT(SoundCue, m_StationLeftSoundCue)
		ADD_OBJECT(SoundCue, m_StationEnteredSoundCue)
		ADD_OBJECT(ScriptClass, StationCollisionClass)
		ADD_OBJECT(TrPawn, r_CurrentPawn)
		ADD_OBJECT(TrStationCollision, m_Collision)
		ADD_VAR(::FloatProperty, m_fStationZOffset, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStation.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStation.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStation.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnEnteredStation(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStation.PawnEnteredStation");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnLeftStation(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStation.PawnLeftStation");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayStationEnteredEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStation.PlayStationEnteredEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStationLeftEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStation.PlayStationLeftEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool BlocksLineChecksFromSourceActor(class Actor* SourceActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStation.BlocksLineChecksFromSourceActor");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = SourceActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
