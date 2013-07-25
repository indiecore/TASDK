#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#include "Engine__SeqAct_ToggleHidden.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SplineActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SplineActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SplineActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SplineActor : public Actor
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'SplineVelocityOverTime'!
		ADD_VAR(::IntProperty, visitedWeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bestPathWeight, 0xFFFFFFFF)
		ADD_OBJECT(SplineActor, previousPath)
		ADD_OBJECT(SplineActor, prevOrdered)
		ADD_OBJECT(SplineActor, nextOrdered)
		ADD_VAR(::BoolProperty, bAlreadyVisited, 0x2)
		ADD_VAR(::BoolProperty, bDisableDestination, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'SplineColor'!
		ADD_STRUCT(::VectorProperty, SplineActorTangent, 0xFFFFFFFF
		Vector GetWorldSpaceTangent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.GetWorldSpaceTangent");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void UpdateSplineComponents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.UpdateSplineComponents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateConnectedSplineComponents(bool bFinish)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.UpdateConnectedSplineComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bFinish;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddConnectionTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.AddConnectionTo");
			byte* params = (byte*)malloc(4);
			*(class SplineActor**)params = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsConnectedTo(class SplineActor* NextActor, bool bCheckForDisableDestination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.IsConnectedTo");
			byte* params = (byte*)malloc(12);
			*(class SplineActor**)params = NextActor;
			*(bool*)(params + 4) = bCheckForDisableDestination;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FindSplineComponentTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.FindSplineComponentTo");
			byte* params = (byte*)malloc(8);
			*(class SplineActor**)params = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		class SplineActor* FindTargetForComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SplineComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.FindTargetForComponent");
			byte* params = (byte*)malloc(8);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SplineComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SplineActor**)(params + 4);
			free(params);
			return returnVal;
		}
		void BreakConnectionTo(class SplineActor* NextActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.BreakConnectionTo");
			byte* params = (byte*)malloc(4);
			*(class SplineActor**)params = NextActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(bool*)params = bUseLinksFrom;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SplineActor**)(params + 4);
			free(params);
			return returnVal;
		}
		class SplineActor* GetBestConnectionInDirection(Vector DesiredDir, bool bUseLinksFrom)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.GetBestConnectionInDirection");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = DesiredDir;
			*(bool*)(params + 12) = bUseLinksFrom;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SplineActor**)(params + 16);
			free(params);
			return returnVal;
		}
		bool FindSplinePathTo(class SplineActor* Goal, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutRoute)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.FindSplinePathTo");
			byte* params = (byte*)malloc(20);
			*(class SplineActor**)params = Goal;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = OutRoute;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutRoute = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void GetAllConnectedSplineActors(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.GetAllConnectedSplineActors");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = OutSet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutSet = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggleHidden(class SeqAct_ToggleHidden* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineActor.OnToggleHidden");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ToggleHidden**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
