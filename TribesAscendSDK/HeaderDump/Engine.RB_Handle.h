#pragma once
#include "Engine.ActorComponent.h"
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
	class RB_Handle : public ActorComponent
	{
	public:
		ADD_STRUCT(Vector, Location, 180)
		ADD_STRUCT(Vector, StepSize, 168)
		ADD_STRUCT(Vector, Destination, 156)
		ADD_STRUCT(float, AngularStiffness, 152)
		ADD_STRUCT(float, AngularDamping, 148)
		ADD_STRUCT(Vector, LinearDampingScale3D, 136)
		ADD_STRUCT(Vector, LinearStiffnessScale3D, 124)
		ADD_STRUCT(float, LinearStiffness, 120)
		ADD_STRUCT(float, LinearDamping, 116)
		ADD_STRUCT(Object::Pointer, KinActorData, 112)
		ADD_STRUCT(Object::Pointer, HandleData, 108)
		ADD_BOOL(bInterpolating, 104, 0x4)
		ADD_BOOL(bRotationConstrained, 104, 0x2)
		ADD_BOOL(bInHardware, 104, 0x1)
		ADD_STRUCT(int, SceneIndex, 100)
		ADD_STRUCT(ScriptName, GrabbedBoneName, 92)
		void GrabComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName InBoneName, Vector GrabLocation, bool bConstrainRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25251);
			byte params[28] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			*(ScriptName*)&params[4] = InBoneName;
			*(Vector*)&params[12] = GrabLocation;
			*(bool*)&params[24] = bConstrainRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReleaseComponent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25256);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLocation(Vector NewLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25257);
			byte params[12] = { NULL };
			*(Vector*)params = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSmoothLocation(Vector NewLocation, float MoveTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25259);
			byte params[16] = { NULL };
			*(Vector*)params = NewLocation;
			*(float*)&params[12] = MoveTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSmoothLocation(Vector& NewLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25262);
			byte params[12] = { NULL };
			*(Vector*)params = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewLocation = *(Vector*)params;
		}
		void SetOrientation(Object::Quat& NewOrientation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25264);
			byte params[16] = { NULL };
			*(Object::Quat*)params = NewOrientation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewOrientation = *(Object::Quat*)params;
		}
		Object::Quat GetOrientation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25266);
			byte params[16] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
