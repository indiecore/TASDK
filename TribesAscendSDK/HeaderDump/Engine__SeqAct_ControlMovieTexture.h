#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_ControlMovieTexture." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ControlMovieTexture : public SequenceAction
	{
	public:
		ADD_OBJECT(TextureMovie, MovieTexture)
	};
}
#undef ADD_OBJECT
