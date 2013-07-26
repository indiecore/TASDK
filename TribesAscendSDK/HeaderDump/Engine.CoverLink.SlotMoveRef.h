#pragma once
#include "Engine.Actor.BasedPosition.h"
#include "Engine.Pylon.PolyReference.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverLink.SlotMoveRef." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty CoverLink.SlotMoveRef." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SlotMoveRef
	{
	public:
		ADD_VAR(::IntProperty, Direction, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<BasedPosition>, Dest, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PolyReference>, Poly, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
