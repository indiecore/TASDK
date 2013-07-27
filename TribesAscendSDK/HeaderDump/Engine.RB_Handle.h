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
		ADD_STRUCT(Object::Vector, Location, 180)
		ADD_STRUCT(Object::Vector, StepSize, 168)
		ADD_STRUCT(Object::Vector, Destination, 156)
		ADD_STRUCT(float, AngularStiffness, 152)
		ADD_STRUCT(float, AngularDamping, 148)
		ADD_STRUCT(Object::Vector, LinearDampingScale3D, 136)
		ADD_STRUCT(Object::Vector, LinearStiffnessScale3D, 124)
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
void* Component, ScriptName InBoneName, Object::Vector GrabLocation, bool bConstrainRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.GrabComponent");
			byte params[28] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = Component;
			*(ScriptName*)&params[4] = InBoneName;
			*(Object::Vector*)&params[12] = GrabLocation;
			*(bool*)&params[24] = bConstrainRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReleaseComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.ReleaseComponent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLocation(Object::Vector NewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.SetLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSmoothLocation(Object::Vector NewLocation, float MoveTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.SetSmoothLocation");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = NewLocation;
			*(float*)&params[12] = MoveTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSmoothLocation(Object::Vector& NewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.UpdateSmoothLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewLocation = *(Object::Vector*)&params[0];
		}
		void SetOrientation(Object::Quat& NewOrientation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.SetOrientation");
			byte params[16] = { NULL };
			*(Object::Quat*)&params[0] = NewOrientation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewOrientation = *(Object::Quat*)&params[0];
		}
		Object::Quat GetOrientation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.GetOrientation");
			byte params[16] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
