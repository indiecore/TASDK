#pragma once
#include "Engine.BookMark2D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class KismetBookMark : public BookMark2D
	{
	public:
		ADD_STRUCT(ScriptString*, BookMarkSequencePathName, 72)
	};
}
#undef ADD_STRUCT
