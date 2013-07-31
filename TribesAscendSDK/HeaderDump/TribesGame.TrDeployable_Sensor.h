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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79943);
			byte params[8] = { NULL };
			*(class Pawn**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DeployComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79949);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ModifyDetectedPawn(class Pawn* DetectedPawn, bool detected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79950);
			byte params[8] = { NULL };
			*(class Pawn**)params = DetectedPawn;
			*(bool*)&params[4] = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPowered(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79958);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79960);
			byte params[4] = { NULL };
			*(class Pawn**)params = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveDetectedPawn(class Pawn* DetectedPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79963);
			byte params[4] = { NULL };
			*(class Pawn**)params = DetectedPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReleaseAllDetectedPawns()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79965);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ManageEnemiesOutOfSight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79966);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleaseOutOfSightEnemies()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79967);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldDetectPawn(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79971);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79974);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInRange(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79977);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79984);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsDeployed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79986);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ScanTargets()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79988);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79990);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79997);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
	};
}
#undef ADD_STRUCT
