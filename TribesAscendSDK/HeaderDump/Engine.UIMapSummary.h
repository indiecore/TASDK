#pragma once
#include "Engine.UIResourceDataProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIMapSummary : public UIResourceDataProvider
	{
	public:
		ADD_STRUCT(ScriptString*, Description, 160)
		ADD_STRUCT(ScriptString*, DisplayName, 148)
		ADD_STRUCT(ScriptString*, ScreenshotPathName, 136)
		ADD_STRUCT(ScriptString*, MapName, 124)
	};
}
#undef ADD_STRUCT
