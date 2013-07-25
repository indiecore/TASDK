#pragma once
#include "Engine__UIConfigProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIConfigFileProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIConfigFileProvider : public UIConfigProvider
	{
	public:
		ADD_VAR(::StrProperty, ConfigFileName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
