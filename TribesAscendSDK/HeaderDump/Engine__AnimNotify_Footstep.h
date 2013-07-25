#pragma once
#include "Engine__AnimNotify.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNotify_Footstep." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNotify_Footstep : public AnimNotify
	{
	public:
		ADD_VAR(::IntProperty, FootDown, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
