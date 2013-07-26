#pragma once
#include "Engine.AnimNodeSequenceBlendBase.AnimInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNodeSequenceBlendBase.AnimBlendInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AnimNodeSequenceBlendBase.AnimBlendInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimBlendInfo
	{
	public:
		ADD_VAR(::FloatProperty, Weight, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AnimInfo>, AnimInfo, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
