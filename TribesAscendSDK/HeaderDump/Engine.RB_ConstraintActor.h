#pragma once
#include "Engine.SeqAct_ToggleConstraintDrive.h"
#include "Engine.RigidBodyBase.h"
#include "Engine.RB_ConstraintSetup.h"
#include "Engine.RB_ConstraintInstance.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Destroy.h"
#include "Engine.SeqAct_Toggle.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class RB_ConstraintActor : public RigidBodyBase
	{
	public:
		ADD_OBJECT(Actor, PulleyPivotActor2, 500)
		ADD_OBJECT(Actor, PulleyPivotActor1, 496)
		ADD_BOOL(bUpdateActor2RefFrame, 492, 0x4)
		ADD_BOOL(bUpdateActor1RefFrame, 492, 0x2)
		ADD_BOOL(bDisableCollision, 492, 0x1)
		ADD_OBJECT(RB_ConstraintInstance, ConstraintInstance, 488)
		ADD_OBJECT(RB_ConstraintSetup, ConstraintSetup, 484)
		ADD_OBJECT(Actor, ConstraintActor2, 480)
		ADD_OBJECT(Actor, ConstraintActor1, 476)
		void SetDisableCollision(bool NewDisableCollision)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25143);
			byte params[4] = { NULL };
			*(bool*)params = NewDisableCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitConstraint(class Actor* Actor1, class Actor* Actor2, ScriptName Actor1Bone, ScriptName Actor2Bone, float BreakThreshold)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25145);
			byte params[28] = { NULL };
			*(class Actor**)params = Actor1;
			*(class Actor**)&params[4] = Actor2;
			*(ScriptName*)&params[8] = Actor1Bone;
			*(ScriptName*)&params[16] = Actor2Bone;
			*(float*)&params[24] = BreakThreshold;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TermConstraint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25151);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnDestroy(class SeqAct_Destroy* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25152);
			byte params[4] = { NULL };
			*(class SeqAct_Destroy**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25154);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleConstraintDrive(class SeqAct_ToggleConstraintDrive* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25158);
			byte params[4] = { NULL };
			*(class SeqAct_ToggleConstraintDrive**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
