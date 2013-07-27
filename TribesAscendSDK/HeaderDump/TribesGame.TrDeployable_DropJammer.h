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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80010);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80013);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80016);
			byte params[4] = { NULL };
			*(class Pawn**)params = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80019);
			byte params[4] = { NULL };
			*(class Pawn**)params = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80028);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
	};
}
