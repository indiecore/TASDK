#pragma once
#include "Engine.AnimNodeAimOffset.AimTransform.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNodeAimOffset.AimComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AnimNodeAimOffset.AimComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AimComponent
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, RD, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, RC, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, RU, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, CD, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, CC, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, CU, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, LD, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, LC, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AimTransform>, LU, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
