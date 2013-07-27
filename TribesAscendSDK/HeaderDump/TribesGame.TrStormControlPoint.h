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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.OnPawnTouched");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		TrStormControlPoint::ControlPointState GetControlPointState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.GetControlPointState");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrStormControlPoint::ControlPointState*)&params[0];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireMissile(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.FireMissile");
			byte params[1] = { NULL };
			params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginTransition(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.BeginTransition");
			byte params[1] = { NULL };
			params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetControlPointState(TrStormControlPoint::ControlPointState NewControlPointState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.SetControlPointState");
			byte params[1] = { NULL };
			*(TrStormControlPoint::ControlPointState*)&params[0] = NewControlPointState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetScreenName(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStormControlPoint.GetScreenName");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_STRUCT
