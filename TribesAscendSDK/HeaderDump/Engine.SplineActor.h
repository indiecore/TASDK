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
		class SplineConnection
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
		ADD_STRUCT(Object::Vector, SplineActorTangent, 488)
		Object::Vector GetWorldSpaceTangent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.GetWorldSpaceTangent");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void UpdateSplineComponents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.UpdateSplineComponents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateConnectedSplineComponents(bool bFinish)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.UpdateConnectedSplineComponents");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bFinish;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddConnectionTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.AddConnectionTo");
			byte params[4] = { NULL };
			*(class SplineActor**)&params[0] = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsConnectedTo(class SplineActor* NextActor, bool bCheckForDisableDestination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.IsConnectedTo");
			byte params[12] = { NULL };
			*(class SplineActor**)&params[0] = NextActor;
			*(bool*)&params[4] = bCheckForDisableDestination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FindSplineComponentTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.FindSplineComponentTo");
			byte params[8] = { NULL };
			*(class SplineActor**)&params[0] = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		class SplineActor* FindTargetForComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SplineComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.FindTargetForComponent");
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SplineComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SplineActor**)&params[4];
		}
		void BreakConnectionTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.BreakConnectionTo");
			byte params[4] = { NULL };
			*(class SplineActor**)&params[0] = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakAllConnections()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.BreakAllConnections");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BreakAllConnectionsFrom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.BreakAllConnectionsFrom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class SplineActor* GetRandomConnection(bool bUseLinksFrom)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.GetRandomConnection");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bUseLinksFrom;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SplineActor**)&params[4];
		}
		class SplineActor* GetBestConnectionInDirection(Object::Vector DesiredDir, bool bUseLinksFrom)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.GetBestConnectionInDirection");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = DesiredDir;
			*(bool*)&params[12] = bUseLinksFrom;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SplineActor**)&params[16];
		}
		bool FindSplinePathTo(class SplineActor* Goal, ScriptArray<class SplineActor*>& OutRoute)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.FindSplinePathTo");
			byte params[20] = { NULL };
			*(class SplineActor**)&params[0] = Goal;
			*(ScriptArray<class SplineActor*>*)&params[4] = OutRoute;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutRoute = *(ScriptArray<class SplineActor*>*)&params[4];
			return *(bool*)&params[16];
		}
		void GetAllConnectedSplineActors(ScriptArray<class SplineActor*>& OutSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.GetAllConnectedSplineActors");
			byte params[12] = { NULL };
			*(ScriptArray<class SplineActor*>*)&params[0] = OutSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutSet = *(ScriptArray<class SplineActor*>*)&params[0];
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleHidden(class SeqAct_ToggleHidden* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.OnToggleHidden");
			byte params[4] = { NULL };
			*(class SeqAct_ToggleHidden**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
