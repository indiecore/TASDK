#pragma once
#include "Engine__ActorComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_Spring." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.RB_Spring." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RB_Spring : public ActorComponent
	{
	public:
		ADD_VAR(::FloatProperty, DampMaxForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DampSaturateVel, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'SpringMaxForceTimeScale'!
		ADD_VAR(::FloatProperty, MaxForceMassRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpringMaxForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpringSaturateDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinBodyMass, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeSinceActivation, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SpringData'!
		ADD_VAR(::BoolProperty, bEnableForceMassRatio, 0x2)
		ADD_VAR(::BoolProperty, bInHardware, 0x1)
		ADD_VAR(::IntProperty, SceneIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName2, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName1, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetComponents'
		// Here lies the not-yet-implemented method 'Clear'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
