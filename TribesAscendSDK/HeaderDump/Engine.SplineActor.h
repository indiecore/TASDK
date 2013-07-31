#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.SeqAct_ToggleHidden.h"
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
	class SplineActor : public Actor
	{
	public:
		struct SplineConnection
		{
		public:
			ADD_OBJECT(SplineActor, ConnectTo, 4)
		};
		ADD_STRUCT(ScriptArray<SplineActor::SplineConnection>, Connections, 476)
		ADD_STRUCT(ScriptArray<class SplineActor*>, LinksFrom, 508)
		ADD_STRUCT(Object::InterpCurveFloat, SplineVelocityOverTime, 540)
		ADD_STRUCT(int, visitedWeight, 536)
		ADD_STRUCT(int, bestPathWeight, 532)
		ADD_OBJECT(SplineActor, previousPath, 528)
		ADD_OBJECT(SplineActor, prevOrdered, 524)
		ADD_OBJECT(SplineActor, nextOrdered, 520)
		ADD_BOOL(bAlreadyVisited, 504, 0x2)
		ADD_BOOL(bDisableDestination, 504, 0x1)
		ADD_STRUCT(Object::Color, SplineColor, 500)
		ADD_STRUCT(Vector, SplineActorTangent, 488)
		Vector GetWorldSpaceTangent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27103);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void UpdateSplineComponents()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27105);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateConnectedSplineComponents(bool bFinish)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27106);
			byte params[4] = { NULL };
			*(bool*)params = bFinish;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddConnectionTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27108);
			byte params[4] = { NULL };
			*(class SplineActor**)params = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsConnectedTo(class SplineActor* NextActor, bool bCheckForDisableDestination)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27110);
			byte params[12] = { NULL };
			*(class SplineActor**)params = NextActor;
			*(bool*)&params[4] = bCheckForDisableDestination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FindSplineComponentTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27114);
			byte params[8] = { NULL };
			*(class SplineActor**)params = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		class SplineActor* FindTargetForComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SplineComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27117);
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SplineComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SplineActor**)&params[4];
		}
		void BreakConnectionTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27120);
			byte params[4] = { NULL };
			*(class SplineActor**)params = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakAllConnections()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27122);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BreakAllConnectionsFrom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27123);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class SplineActor* GetRandomConnection(bool bUseLinksFrom)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27124);
			byte params[8] = { NULL };
			*(bool*)params = bUseLinksFrom;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SplineActor**)&params[4];
		}
		class SplineActor* GetBestConnectionInDirection(Vector DesiredDir, bool bUseLinksFrom)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27127);
			byte params[20] = { NULL };
			*(Vector*)params = DesiredDir;
			*(bool*)&params[12] = bUseLinksFrom;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SplineActor**)&params[16];
		}
		bool FindSplinePathTo(class SplineActor* Goal, ScriptArray<class SplineActor*>& OutRoute)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27131);
			byte params[20] = { NULL };
			*(class SplineActor**)params = Goal;
			*(ScriptArray<class SplineActor*>*)&params[4] = OutRoute;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutRoute = *(ScriptArray<class SplineActor*>*)&params[4];
			return *(bool*)&params[16];
		}
		void GetAllConnectedSplineActors(ScriptArray<class SplineActor*>& OutSet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27136);
			byte params[12] = { NULL };
			*(ScriptArray<class SplineActor*>*)params = OutSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutSet = *(ScriptArray<class SplineActor*>*)params;
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27139);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleHidden(class SeqAct_ToggleHidden* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27141);
			byte params[4] = { NULL };
			*(class SeqAct_ToggleHidden**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
