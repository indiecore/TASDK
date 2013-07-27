#pragma once
#include "Engine.Volume.h"
#include "Core.Object.h"
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
	class EnvironmentVolume : public Volume
	{
	public:
		ADD_BOOL(bSplitNavMesh, 528, 0x1)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_NavMeshPathObject, 524)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_NavMeshPathObstacle, 520)
		void SetSplitNavMesh(bool bNewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15594);
			byte params[4] = { NULL };
			*(bool*)params = bNewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
