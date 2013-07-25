#pragma once
#include "Engine.AnimNotify.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNotify_Script." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNotify_Script : public AnimNotify
	{
	public:
		ADD_VAR(::NameProperty, NotifyEndName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, NotifyTickName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, NotifyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
