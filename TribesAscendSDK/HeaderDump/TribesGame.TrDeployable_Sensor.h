#pragma once
#include "TribesGame.TrDeployable.h"
#include "Engine.Texture2D.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_Sensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_Sensor : public TrDeployable
	{
	public:
		ADD_VAR(::FloatProperty, m_fDetectionZOffset, 0xFFFFFFFF)
		bool CheckLOS(class Pawn* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.CheckLOS");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DeployComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.DeployComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ModifyDetectedPawn(class Pawn* DetectedPawn, bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.ModifyDetectedPawn");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = DetectedPawn;
			*(bool*)(params + 4) = detected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPowered(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.SetPowered");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.AddDetectedPawn");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.RemoveDetectedPawn");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.OnPawnDetectedByCollisionProxy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsInRange(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.IsInRange");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.OnPawnExitedCollisionProxy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsDeployed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_Sensor.IsDeployed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
