#pragma once
#include "Engine__Info.h"
#include "Engine__Controller.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_CrashLandInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrCallIn_CrashLandInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_CrashLandInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_CrashLandInfo : public Info
	{
	public:
		ADD_VAR(::FloatProperty, MomentumTransfer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Damage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageRadius, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DamageTypeClass)
		ADD_STRUCT(::VectorProperty, r_CrashLandNormal, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, r_CrashLandPoint, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, r_fCrashLandTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bPodLanded, 0x1)
		ADD_OBJECT(Controller, m_Owner)
		ADD_OBJECT(ScriptClass, m_ItemToDeploy)
		bool SpawnCrashLandInfo(class Controller* Initializer, float CrashLandTime, Vector CrashLandPoint, Vector CrashLandNormal, ScriptClass* ItemInDeliveryPod)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_CrashLandInfo.SpawnCrashLandInfo");
			byte* params = (byte*)malloc(40);
			*(class Controller**)params = Initializer;
			*(float*)(params + 4) = CrashLandTime;
			*(Vector*)(params + 8) = CrashLandPoint;
			*(Vector*)(params + 20) = CrashLandNormal;
			*(ScriptClass**)(params + 32) = ItemInDeliveryPod;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_CrashLandInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_CrashLandInfo.InitTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeliveryPodLanded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_CrashLandInfo.DeliveryPodLanded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveSameTeamPawn(class TrPawn* PawnToMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_CrashLandInfo.MoveSameTeamPawn");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = PawnToMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PerformLandingDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_CrashLandInfo.PerformLandingDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
