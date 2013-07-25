#pragma once
#include "Engine__AnimNodeScalePlayRate.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeScaleRateBySpeed." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeScaleRateBySpeed : public AnimNodeScalePlayRate
	{
	public:
		ADD_VAR(::FloatProperty, BaseSpeed, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
