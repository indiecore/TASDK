#pragma once
#include "Engine__AnimNodeBlendList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendBase : public AnimNodeBlendList
	{
	public:
		ADD_VAR(::BoolProperty, bTickAnimInScript, 0x1)
		ADD_VAR(::FloatProperty, BlendTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
