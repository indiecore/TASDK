#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class EdCoordSystem : public Object
	{
	public:
		ADD_STRUCT(ScriptString*, Desc, 128)
		ADD_STRUCT(Object::Matrix, M, 64)
	};
}
#undef ADD_STRUCT
