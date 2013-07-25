#pragma once
#include "Engine__AnimNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeBlendBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendBase : public AnimNode
	{
	public:
		ADD_VAR(::ByteProperty, BlendType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFixNumChildren, 0x1)
	};
}
#undef ADD_VAR
