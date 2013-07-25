#pragma once
#include "Engine.RigidBodyBase.h"
#include "Engine.SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_CylindricalForceActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.RB_CylindricalForceActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RB_CylindricalForceActor : public RigidBodyBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer' for the property named 'CollideWithChannels'!
		ADD_VAR(::BoolProperty, bForceApplyToProjectiles, 0x10)
		ADD_VAR(::BoolProperty, bForceApplyToRigidBodies, 0x8)
		ADD_VAR(::BoolProperty, bForceApplyToFluid, 0x4)
		ADD_VAR(::BoolProperty, bForceApplyToCloth, 0x2)
		ADD_VAR(::BoolProperty, bForceActive, 0x1)
		ADD_VAR(::FloatProperty, HeightOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceTopRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EscapeVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LiftFalloffHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LiftStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotationalStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialStrength, 0xFFFFFFFF)
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_CylindricalForceActor.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
