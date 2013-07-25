#pragma once
#include "Engine__SeqAct_ToggleConstraintDrive.h"
#include "Engine__RB_ConstraintSetup.h"
#include "Engine__RigidBodyBase.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#include "Engine__RB_ConstraintInstance.h"
#include "Engine__SeqAct_Destroy.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_ConstraintActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.RB_ConstraintActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class RB_ConstraintActor : public RigidBodyBase
	{
	public:
		ADD_OBJECT(Actor, PulleyPivotActor2)
		ADD_OBJECT(Actor, PulleyPivotActor1)
		ADD_VAR(::BoolProperty, bUpdateActor2RefFrame, 0x4)
		ADD_VAR(::BoolProperty, bUpdateActor1RefFrame, 0x2)
		ADD_VAR(::BoolProperty, bDisableCollision, 0x1)
		ADD_OBJECT(RB_ConstraintInstance, ConstraintInstance)
		ADD_OBJECT(RB_ConstraintSetup, ConstraintSetup)
		ADD_OBJECT(Actor, ConstraintActor2)
		ADD_OBJECT(Actor, ConstraintActor1)
		void SetDisableCollision(bool NewDisableCollision)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintActor.SetDisableCollision");
			byte* params = (byte*)malloc(4);
			*(bool*)params = NewDisableCollision;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitConstraint(class Actor* Actor1, class Actor* Actor2, ScriptName Actor1Bone, ScriptName Actor2Bone, float BreakThreshold)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintActor.InitConstraint");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Actor1;
			*(class Actor**)(params + 4) = Actor2;
			*(ScriptName*)(params + 8) = Actor1Bone;
			*(ScriptName*)(params + 16) = Actor2Bone;
			*(float*)(params + 24) = BreakThreshold;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TermConstraint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintActor.TermConstraint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnDestroy(class SeqAct_Destroy* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintActor.OnDestroy");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Destroy**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintActor.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggleConstraintDrive(class SeqAct_ToggleConstraintDrive* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintActor.OnToggleConstraintDrive");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ToggleConstraintDrive**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
