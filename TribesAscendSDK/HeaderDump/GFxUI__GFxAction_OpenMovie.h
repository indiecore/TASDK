#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUI.GFxAction_OpenMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxUI.GFxAction_OpenMovie." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxAction_OpenMovie : public SequenceAction
	{
	public:
		ADD_OBJECT(TextureRenderTarget2D, RenderTexture)
		ADD_VAR(::ByteProperty, RenderTextureMode, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisplayWithHudOff, 0x10)
		ADD_VAR(::BoolProperty, bEnableGammaCorrection, 0x8)
		ADD_VAR(::BoolProperty, bStartPaused, 0x4)
		ADD_VAR(::BoolProperty, bCaptureInput, 0x2)
		ADD_VAR(::BoolProperty, bTakeFocus, 0x1)
		ADD_OBJECT(GFxMoviePlayer, MoviePlayer)
		ADD_OBJECT(SwfMovie, Movie)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
