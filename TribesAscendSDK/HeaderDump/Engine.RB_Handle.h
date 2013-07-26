#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Quat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_Handle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.RB_Handle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RB_Handle : public ActorComponent
	{
	public:
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StepSize, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Destination, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngularStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngularDamping, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LinearDampingScale3D, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LinearStiffnessScale3D, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearDamping, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, KinActorData, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, HandleData, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInterpolating, 0x4)
		ADD_VAR(::BoolProperty, bRotationConstrained, 0x2)
		ADD_VAR(::BoolProperty, bInHardware, 0x1)
		ADD_VAR(::IntProperty, SceneIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, GrabbedBoneName, 0xFFFFFFFF)
		void GrabComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName InBoneName, Vector GrabLocation, bool bConstrainRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.GrabComponent");
			byte* params = (byte*)malloc(28);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			*(ScriptName*)(params + 4) = InBoneName;
			*(Vector*)(params + 12) = GrabLocation;
			*(bool*)(params + 24) = bConstrainRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReleaseComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.ReleaseComponent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLocation(Vector NewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.SetLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSmoothLocation(Vector NewLocation, float MoveTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.SetSmoothLocation");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = NewLocation;
			*(float*)(params + 12) = MoveTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSmoothLocation(Vector& NewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.UpdateSmoothLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewLocation = *(Vector*)params;
			free(params);
		}
		void SetOrientation(Quat& NewOrientation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.SetOrientation");
			byte* params = (byte*)malloc(16);
			*(Quat*)params = NewOrientation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewOrientation = *(Quat*)params;
			free(params);
		}
		Quat GetOrientation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Handle.GetOrientation");
			byte* params = (byte*)malloc(16);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Quat*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
