#pragma once
#include "Core.Object.Vector.h"
#include "GameFramework.GameAICommand.h"
#include "Engine.ReachSpec.h"
#include "Engine.Actor.h"
#include "GameFramework.GameAIController.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameAICmd_Hover_MoveToGoal." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameAICmd_Hover_MoveToGoal." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameAICmd_Hover_MoveToGoal." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameAICmd_Hover_MoveToGoal : public GameAICommand
	{
	public:
		ADD_OBJECT(ReachSpec, CurrentSpec)
		ADD_STRUCT(::VectorProperty, MoveVectDest, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GoalDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SubGoalReachDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentHoverHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredHoverHeight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWasFiring, 0x1)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Goal)
		ADD_OBJECT(Actor, Find)
		ADD_OBJECT(Actor, Path)
		bool MoveToGoal(class GameAIController* AI, class Actor* InGoal, float InGoalDistance, float InHoverHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICmd_Hover_MoveToGoal.MoveToGoal");
			byte* params = (byte*)malloc(20);
			*(class GameAIController**)params = AI;
			*(class Actor**)(params + 4) = InGoal;
			*(float*)(params + 8) = InGoalDistance;
			*(float*)(params + 12) = InHoverHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void Pushed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICmd_Hover_MoveToGoal.Pushed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICmd_Hover_MoveToGoal.HandlePathObstruction");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsEnemyBasedOnInterpActor(class Pawn* InEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameAICmd_Hover_MoveToGoal.IsEnemyBasedOnInterpActor");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = InEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
