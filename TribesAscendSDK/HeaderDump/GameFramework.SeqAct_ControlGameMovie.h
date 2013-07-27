#pragma once
#include "Engine.SeqAct_Latent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ControlGameMovie : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(int, EndOfRenderingMovieFrame, 264)
		ADD_STRUCT(int, StartOfRenderingMovieFrame, 260)
		ADD_STRUCT(ScriptString*, MovieName, 248)
	};
}
#undef ADD_STRUCT
