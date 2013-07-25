#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNode : public Object
	{
	public:
		ADD_VAR(::IntProperty, NodeUpdateHint, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
