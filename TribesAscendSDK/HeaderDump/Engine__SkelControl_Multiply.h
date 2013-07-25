#pragma once
#include "Engine__SkelControlBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkelControl_Multiply." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControl_Multiply : public SkelControlBase
	{
	public:
		ADD_VAR(::FloatProperty, Multiplier, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
