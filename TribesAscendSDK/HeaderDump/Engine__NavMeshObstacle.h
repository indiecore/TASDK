#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshObstacle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshObstacle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshObstacle : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bPreserveInternalGeo, 0x2)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_NavMeshPathObstacle'!
		bool GetObstacleBoudingShape(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Shape)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshObstacle.GetObstacleBoudingShape");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Shape;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Shape = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void RegisterObstacle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshObstacle.RegisterObstacle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnRegisterObstacle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshObstacle.UnRegisterObstacle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshObstacle.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshObstacle.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetEnabled(bool bInEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshObstacle.SetEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
