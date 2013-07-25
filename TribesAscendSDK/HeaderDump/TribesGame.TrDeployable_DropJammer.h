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
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.AddDetectedPawn");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.RemoveDetectedPawn");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_DropJammer.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
	};
}
