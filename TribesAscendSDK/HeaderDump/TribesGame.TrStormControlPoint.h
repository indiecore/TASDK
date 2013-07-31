#pragma once
#include "Core.Object.h"
#include "TribesGame.TrGameObjective.h"
#include "Engine.PlayerController.h"
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrInventoryStation_Storm.h"
#include "Engine.Canvas.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrStormControlPoint : public TrGameObjective
	{
	public:
		enum ControlPointState : byte
		{
			ControlPointState_Neutral = 0,
			ControlPointState_FullyOwnedBE = 1,
			ControlPointState_FullyOwnedDS = 2,
			ControlPointState_TransitioningToBE = 3,
			ControlPointState_TransitioningToDS = 4,
			ControlPointState_MAX = 5,
		};
		ADD_STRUCT(ScriptArray<class TrInventoryStation_Storm*>, m_InventoryStations, 1392)
		ADD_STRUCT(ScriptString*, m_sControlPointName, 1404)
		ADD_STRUCT(float, m_fLaunchTimeDescriptionPlacementY, 1388)
		ADD_STRUCT(float, m_fControlDescriptionPlacementY, 1384)
		ADD_STRUCT(float, m_fMissileFlightTime, 1380)
		ADD_STRUCT(float, m_fMissileLaunchTrackerSpeed, 1376)
		ADD_STRUCT(float, m_fMissileLaunchTracker, 1372)
		ADD_STRUCT(float, m_fCurrentTransitionAmount, 1368)
		ADD_STRUCT(float, m_fTransitionSpeed, 1364)
		ADD_STRUCT(TrStormControlPoint::ControlPointState, r_CurrentControlPointState, 1360)
		void OnPawnTouched(class TrPawn* TRP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112762);
			byte params[4] = { NULL };
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		TrStormControlPoint::ControlPointState GetControlPointState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112765);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrStormControlPoint::ControlPointState*)params;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112767);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireMissile(byte TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112769);
			byte params[1] = { NULL };
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginTransition(byte TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112772);
			byte params[1] = { NULL };
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetControlPointState(TrStormControlPoint::ControlPointState NewControlPointState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112775);
			byte params[1] = { NULL };
			*(TrStormControlPoint::ControlPointState*)params = NewControlPointState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112780);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetScreenName(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112791);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_STRUCT
