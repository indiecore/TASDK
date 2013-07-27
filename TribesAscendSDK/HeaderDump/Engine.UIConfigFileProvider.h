#pragma once
#include "Engine.UIConfigProvider.h"
#include "Engine.UIConfigSectionProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIConfigFileProvider : public UIConfigProvider
	{
	public:
		ADD_STRUCT(ScriptArray<class UIConfigSectionProvider*>, Sections, 88)
		ADD_STRUCT(ScriptString*, ConfigFileName, 100)
	};
}
#undef ADD_STRUCT
