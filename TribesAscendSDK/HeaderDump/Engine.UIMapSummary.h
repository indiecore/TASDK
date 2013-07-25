#pragma once
#include "Engine.UIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIMapSummary." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIMapSummary : public UIResourceDataProvider
	{
	public:
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DisplayName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScreenshotPathName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
