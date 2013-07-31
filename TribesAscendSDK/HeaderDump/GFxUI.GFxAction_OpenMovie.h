#pragma once
#include "Engine.TextureRenderTarget2D.h"
#include "Engine.SequenceAction.h"
#include "GFxUI.GFxMoviePlayer.h"
#include "GFxUI.SwfMovie.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxAction_OpenMovie : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, CaptureKeys, 256)
		ADD_STRUCT(ScriptArray<ScriptName>, FocusIgnoreKeys, 268)
		ADD_OBJECT(TextureRenderTarget2D, RenderTexture, 252)
		ADD_STRUCT(GFxMoviePlayer::GFxRenderTextureMode, RenderTextureMode, 248)
		ADD_BOOL(bDisplayWithHudOff, 244, 0x10)
		ADD_BOOL(bEnableGammaCorrection, 244, 0x8)
		ADD_BOOL(bStartPaused, 244, 0x4)
		ADD_BOOL(bCaptureInput, 244, 0x2)
		ADD_BOOL(bTakeFocus, 244, 0x1)
		ADD_OBJECT(GFxMoviePlayer, MoviePlayer, 240)
		ADD_OBJECT(ScriptClass, MoviePlayerClass, 236)
		ADD_OBJECT(SwfMovie, Movie, 232)
		bool IsValidLevelSequenceObject()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29962);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
