#pragma once
#include "Engine.InterpTrackInstProperty.h"
#include "Core.Object.Color.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackInstColorProp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstColorProp : public InterpTrackInstProperty
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Color>, ResetColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ColorProp, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
