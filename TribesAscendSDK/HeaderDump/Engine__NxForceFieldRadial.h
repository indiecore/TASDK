#pragma once
#include "Engine__NxForceField.h"
#include "Engine__ForceFieldShape.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Kernel'!
		ADD_VAR(::ByteProperty, ForceFalloff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SelfRotationStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceStrength, 0xFFFFFFFF)
		ADD_OBJECT(ForceFieldShape, Shape)
		// Here lies the not-yet-implemented method 'DoInitRBPhys'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
