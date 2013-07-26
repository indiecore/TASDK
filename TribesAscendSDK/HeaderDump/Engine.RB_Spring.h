#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.InterpCurveFloat.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Vector.h"
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
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveFloat>, SpringMaxForceTimeScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxForceMassRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpringMaxForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpringSaturateDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinBodyMass, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeSinceActivation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, SpringData, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableForceMassRatio, 0x2)
		ADD_VAR(::BoolProperty, bInHardware, 0x1)
		ADD_VAR(::IntProperty, SceneIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName2, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName1, 0xFFFFFFFF)
		void SetComponents(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InComponent1, ScriptName InBoneName1, Vector Position1, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InComponent2, ScriptName InBoneName2, Vector Position2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Spring.SetComponents");
			byte* params = (byte*)malloc(48);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = InComponent1;
			*(ScriptName*)(params + 4) = InBoneName1;
			*(Vector*)(params + 12) = Position1;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 24) = InComponent2;
			*(ScriptName*)(params + 28) = InBoneName2;
			*(Vector*)(params + 36) = Position2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Clear()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_Spring.Clear");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
