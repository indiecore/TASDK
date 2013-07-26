#pragma once
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Core.Object.Vector.h"
#include "Engine.NavigationHandle.h"
#include "Core.Object.Pointer.h"
#include "Engine.NavMeshGoal_Filter.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoal_GenericFilterContainer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavMeshGoal_GenericFilterContainer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshGoal_GenericFilterContainer : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_OBJECT(NavigationHandle, MyNavigationHandle)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, SuccessfulGoal, 0xFFFFFFFF)
		class NavMeshGoal_GenericFilterContainer* CreateAndAddFilterToNavHandle(class NavigationHandle* NavHandle, int InMaxPathVisits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_GenericFilterContainer.CreateAndAddFilterToNavHandle");
			byte* params = (byte*)malloc(12);
			*(class NavigationHandle**)params = NavHandle;
			*(int*)(params + 4) = InMaxPathVisits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavMeshGoal_GenericFilterContainer**)(params + 8);
			free(params);
			return returnVal;
		}
		class NavMeshGoal_Filter* GetFilterOfType(ScriptClass* Filter_Class)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_GenericFilterContainer.GetFilterOfType");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = Filter_Class;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavMeshGoal_Filter**)(params + 4);
			free(params);
			return returnVal;
		}
		Vector GetGoalPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_GenericFilterContainer.GetGoalPoint");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_GenericFilterContainer.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
