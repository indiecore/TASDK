#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InGameAdManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InGameAdManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bShouldPauseWhileAdOpen, 0x1)
	};
}
#undef ADD_VAR
