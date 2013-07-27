#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshObstacle : public Actor
	{
	public:
		ADD_BOOL(bPreserveInternalGeo, 480, 0x2)
		ADD_BOOL(bEnabled, 480, 0x1)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_NavMeshPathObstacle, 476)
		bool GetObstacleBoudingShape(ScriptArray<Object::Vector>& Shape)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshObstacle.GetObstacleBoudingShape");
			byte params[16] = { NULL };
			*(ScriptArray<Object::Vector>*)&params[0] = Shape;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Shape = *(ScriptArray<Object::Vector>*)&params[0];
			return *(bool*)&params[12];
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
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEnabled(bool bInEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshObstacle.SetEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
