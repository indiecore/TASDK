#pragma once
#include "Engine.WorldInfo.PhysXEmitterVerticalProperties.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty WorldInfo.PhysXVerticalProperties." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PhysXVerticalProperties
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<PhysXEmitterVerticalProperties>, Emitters, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
