#pragma once
#include "Engine.CoverLink.CoverReference.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverLink.ExposedLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty CoverLink.ExposedLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ExposedLink
	{
	public:
		ADD_VAR(::ByteProperty, ExposedScale, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<CoverReference>, TargetActor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
