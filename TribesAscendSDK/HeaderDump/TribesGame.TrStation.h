#pragma once
#include "Engine.Actor.h"
#include "TribesGame.TrGameObjective.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrCaHCapturePoint.h"
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrStationCollision.h"
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
	class TrStation : public TrGameObjective
	{
	public:
		ADD_OBJECT(TrCaHCapturePoint, m_OwningCaHCapturePoint, 1392)
		ADD_OBJECT(SoundCue, m_StationLeftSoundCue, 1384)
		ADD_OBJECT(SoundCue, m_StationEnteredSoundCue, 1376)
		ADD_OBJECT(ScriptClass, StationCollisionClass, 1372)
		ADD_OBJECT(TrPawn, r_CurrentPawn, 1368)
		ADD_OBJECT(TrStationCollision, m_Collision, 1364)
		ADD_STRUCT(float, m_fStationZOffset, 1360)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98171);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98172);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98174);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnEnteredStation(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98175);
			byte params[4] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeftStation(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98178);
			byte params[4] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayStationEnteredEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98181);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStationLeftEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98184);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool BlocksLineChecksFromSourceActor(class Actor* SourceActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98185);
			byte params[8] = { NULL };
			*(class Actor**)params = SourceActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
