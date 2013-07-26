#pragma once
#include "Engine.UIRoot.InputEventParameters.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.SubscribedInputEventParameters." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SubscribedInputEventParameters : public InputEventParameters
	{
	public:
		ADD_VAR(::NameProperty, InputAliasName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
