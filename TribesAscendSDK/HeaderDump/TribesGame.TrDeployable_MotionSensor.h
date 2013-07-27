#pragma once
#include "TribesGame.TrDeployable_Sensor.h"
#include "Engine.PlayerController.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Pawn.h"
#include "Engine.Texture2D.h"
#include "Core.Object.h"
#include "Engine.Canvas.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class TrDeployable_MotionSensor : public TrDeployable_Sensor
	{
	public:
		struct MotionSensorEnemyInfo
		{
		public:
			ADD_STRUCT(float, LastDetectedTimeStamp, 16)
			ADD_STRUCT(Vector, LastLocation, 4)
			ADD_OBJECT(TrPawn, SensedPawn, 0)
		};
		ADD_STRUCT(ScriptArray<TrDeployable_MotionSensor::MotionSensorEnemyInfo>, m_EnemyPawnsInRange, 1540)
		ADD_OBJECT(Texture2D, m_AlarmIcon, 1616)
		ADD_STRUCT(Vector, LastCameraPos, 1604)
		ADD_STRUCT(Vector, LastCameraDir, 1592)
		ADD_STRUCT(Vector, LastScreenLoc, 1580)
		ADD_STRUCT(float, m_IconAlpha, 1576)
		ADD_STRUCT(float, m_fHUDAlarmTime, 1572)
		ADD_BOOL(m_bDrawHUDAlarm, 1568, 0x1)
		ADD_STRUCT(float, m_fLastAlarmTimestamp, 1564)
		ADD_STRUCT(float, m_fTimeBetweenAlarms, 1560)
		ADD_STRUCT(float, m_fMotionSenseExpireTime, 1556)
		void DeployComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80134);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80135);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80138);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateInRangeEnemyPawns()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80141);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanSetOffAlarm(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80145);
			byte params[8] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ModifyDetectedPawn(class Pawn* DetectedPawn, bool detected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80148);
			byte params[8] = { NULL };
			*(class Pawn**)params = DetectedPawn;
			*(bool*)&params[4] = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAlarm()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80151);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TriggerHUDAlarm()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80156);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideHUDAlarm()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80157);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80158);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(80169);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
