#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.PrimitiveComponent.RBCollisionChannelContainer.h"
#include "Engine.ForceFieldShape.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxForceFieldComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxForceFieldComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NxForceFieldComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NxForceFieldComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, RBPhysScene, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SceneIndex, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ForceField, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RBCollisionChannelContainer>, CollideWithChannels, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDestroyWhenInactive, 0x2)
		ADD_VAR(::BoolProperty, bForceActive, 0x1)
		ADD_VAR(::IntProperty, ExcludeChannel, 0xFFFFFFFF)
		ADD_OBJECT(ForceFieldShape, Shape)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxForceFieldComponent.DoInitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
