#pragma once
#include "Core.Factory.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TextureMovieFactory : public Factory
	{
	public:
		enum MovieStreamSource : byte
		{
			MovieStream_File = 0,
			MovieStream_Memory = 1,
			MovieStream_MAX = 2,
		};
		ADD_STRUCT(TextureMovieFactory::MovieStreamSource, MovieStreamSource, 112)
	};
}
#undef ADD_STRUCT
