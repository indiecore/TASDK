#pragma once
#include "TribesGame.TrDeployable_Sensor.h"
#include "Engine.PlayerController.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Pawn.h"
#include "Engine.Texture2D.h"
#include "Core.Object.Vector.h"
#include "Engine.Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_MotionSensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDeployable_MotionSensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable_MotionSensor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_MotionSensor : public TrDeployable_Sensor
	{
	public:
		ADD_OBJECT(Texture2D, m_AlarmIcon)
		ADD_STRUCT(::VectorProperty, LastCameraPos, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastCameraDir, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastScreenLoc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_IconAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHUDAlarmTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bDrawHUDAlarm, 0x1)
		ADD_VAR(::FloatProperty, m_fLastAlarmTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeBetweenAlarms, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMotionSenseExpireTime, 0xFFFFFFFF)
		void DeployComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.DeployComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.OnPawnDetectedByCollisionProxy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.OnPawnExitedCollisionProxy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateInRangeEnemyPawns()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.UpdateInRangeEnemyPawns");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanSetOffAlarm(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.CanSetOffAlarm");
			byte* params = (byte*)malloc(8);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ModifyDetectedPawn(class Pawn* DetectedPawn, bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.ModifyDetectedPawn");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = DetectedPawn;
			*(bool*)(params + 4) = detected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayAlarm()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.PlayAlarm");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TriggerHUDAlarm()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.TriggerHUDAlarm");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideHUDAlarm()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.HideHUDAlarm");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_MotionSensor.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
