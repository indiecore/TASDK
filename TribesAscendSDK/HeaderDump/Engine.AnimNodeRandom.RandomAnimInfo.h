#pragma once
#include "Core.Object.Vector2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNodeRandom.RandomAnimInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AnimNodeRandom.RandomAnimInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RandomAnimInfo
	{
	public:
		ADD_VAR(::FloatProperty, LastPosition, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LoopCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bStillFrame, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, PlayRateRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LoopCountMax, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LoopCountMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Chance, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
