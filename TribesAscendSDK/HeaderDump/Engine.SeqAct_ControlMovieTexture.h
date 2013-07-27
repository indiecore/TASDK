#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.TextureMovie.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ControlMovieTexture : public SequenceAction
	{
	public:
		enum EMovieControlType : byte
		{
			MCT_Play = 0,
			MCT_Stop = 1,
			MCT_Pause = 2,
			MCT_MAX = 3,
		};
		ADD_OBJECT(TextureMovie, MovieTexture, 232)
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_ControlMovieTexture.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
