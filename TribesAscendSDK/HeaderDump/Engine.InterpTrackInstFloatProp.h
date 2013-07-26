#pragma once
#include "Engine.InterpTrackInstProperty.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackInstFloatProp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackInstFloatProp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstFloatProp : public InterpTrackInstProperty
	{
	public:
		ADD_VAR(::FloatProperty, ResetFloat, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, FloatProp, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
