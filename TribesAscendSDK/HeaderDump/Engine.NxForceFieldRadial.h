#pragma once
#include "Engine.NxForceField.h"
#include "Core.Object.Pointer.h"
#include "Engine.ForceFieldShape.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxForceFieldRadial." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxForceFieldRadial." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NxForceFieldRadial." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NxForceFieldRadial : public NxForceField
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Kernel, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ForceFalloff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SelfRotationStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceStrength, 0xFFFFFFFF)
		ADD_OBJECT(ForceFieldShape, Shape)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxForceFieldRadial.DoInitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
