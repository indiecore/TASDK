#pragma once
#include "Engine__LocalMessage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FailedConnect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FailedConnect : public LocalMessage
	{
	public:
		ADD_VAR(::StrProperty, FailMessage, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
