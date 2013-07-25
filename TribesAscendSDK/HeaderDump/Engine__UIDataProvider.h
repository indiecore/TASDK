#pragma once
#include "Engine__UIRoot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider : public UIRoot
	{
	public:
		ADD_VAR(::ByteProperty, WriteAccessType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
