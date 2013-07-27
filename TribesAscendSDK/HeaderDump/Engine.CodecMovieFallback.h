#pragma once
#include "Engine.CodecMovie.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class CodecMovieFallback : public CodecMovie
	{
	public:
		ADD_STRUCT(float, CurrentTime, 64)
	};
}
#undef ADD_STRUCT
