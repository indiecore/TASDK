#pragma once
#include "TribesGame.TrDeployable.h"
#include "Engine.Texture2D.h"
#include "Engine.Pawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_Sensor : public TrDeployable
	{
	public:
		ADD_STRUCT(ScriptArray<class Pawn*>, m_DetectedPawns, 1524)
		ADD_STRUCT(float, m_fDetectionZOffset, 1536)
		bool CheckLOS(class Pawn* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.CheckLOS");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DeployComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.DeployComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ModifyDetectedPawn(class Pawn* DetectedPawn, bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.ModifyDetectedPawn");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = DetectedPawn;
			*(bool*)&params[4] = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPowered(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.SetPowered");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.AddDetectedPawn");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.RemoveDetectedPawn");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReleaseAllDetectedPawns()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.ReleaseAllDetectedPawns");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ManageEnemiesOutOfSight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.ManageEnemiesOutOfSight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleaseOutOfSightEnemies()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.ReleaseOutOfSightEnemies");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldDetectPawn(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.ShouldDetectPawn");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.OnPawnDetectedByCollisionProxy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInRange(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.IsInRange");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.OnPawnExitedCollisionProxy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsDeployed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.IsDeployed");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ScanTargets()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.ScanTargets");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.GetMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
	};
}
#undef ADD_STRUCT
