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
		bool GetObstacleBoudingShape(ScriptArray<Vector>& Shape)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21027);
			byte params[16] = { NULL };
			*(ScriptArray<Vector>*)params = Shape;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Shape = *(ScriptArray<Vector>*)params;
			return *(bool*)&params[12];
		}
		void RegisterObstacle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21033);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnRegisterObstacle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21034);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21035);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21036);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEnabled(bool bInEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21038);
			byte params[4] = { NULL };
			*(bool*)params = bInEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
