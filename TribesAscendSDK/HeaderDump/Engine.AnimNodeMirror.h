#pragma once
#include "Engine.AnimNodeBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeMirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeMirror : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::BoolProperty, bEnableMirroring, 0x1)
	};
}
#undef ADD_VAR
