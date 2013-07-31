#pragma once
#include "Engine.UIConfigProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIConfigSectionProvider : public UIConfigProvider
	{
	public:
		ADD_STRUCT(ScriptString*, SectionName, 88)
	};
}
#undef ADD_STRUCT
