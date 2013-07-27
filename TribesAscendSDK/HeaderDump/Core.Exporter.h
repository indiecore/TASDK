#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Exporter : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, FormatExtension, 64)
		ADD_STRUCT(ScriptArray<ScriptString*>, FormatDescription, 76)
	};
}
#undef ADD_STRUCT
