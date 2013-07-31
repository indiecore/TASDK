#pragma once
#include "TribesGame.TrPawn.h"
#include "Engine.Info.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
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
	class TrCallIn_CrashLandInfo : public Info
	{
	public:
		ADD_STRUCT(float, MomentumTransfer, 528)
		ADD_STRUCT(float, Damage, 524)
		ADD_STRUCT(float, DamageRadius, 520)
		ADD_OBJECT(ScriptClass, DamageTypeClass, 516)
		ADD_STRUCT(Vector, r_CrashLandNormal, 504)
		ADD_STRUCT(Vector, r_CrashLandPoint, 492)
		ADD_STRUCT(float, r_fCrashLandTime, 488)
		ADD_BOOL(r_bPodLanded, 484, 0x1)
		ADD_OBJECT(Controller, m_Owner, 480)
		ADD_OBJECT(ScriptClass, m_ItemToDeploy, 476)
		bool SpawnCrashLandInfo(class Controller* Initializer, float CrashLandTime, Vector CrashLandPoint, Vector CrashLandNormal, ScriptClass* ItemInDeliveryPod)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73992);
			byte params[40] = { NULL };
			*(class Controller**)params = Initializer;
			*(float*)&params[4] = CrashLandTime;
			*(Vector*)&params[8] = CrashLandPoint;
			*(Vector*)&params[20] = CrashLandNormal;
			*(ScriptClass**)&params[32] = ItemInDeliveryPod;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74000);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74001);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeliveryPodLanded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74005);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveSameTeamPawn(class TrPawn* PawnToMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74007);
			byte params[4] = { NULL };
			*(class TrPawn**)params = PawnToMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PerformLandingDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74013);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
