#pragma once
#include "TribesGame.TrDeployable_Sensor.h"
#include "Engine.Texture2D.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class TrDeployable_DropJammer : public TrDeployable_Sensor
	{
	public:
		bool ShouldDetectPawn(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.ShouldDetectPawn");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.AddDetectedPawn");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.RemoveDetectedPawn");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.GetMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
	};
}
