#pragma once
#include "Engine.Texture2D.h"
#include "Core.Object.h"
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
namespace UnrealScript
{
	class TextureFlipBook : public Texture2D
	{
	public:
		enum TextureFlipBookMethod : byte
		{
			TFBM_UL_ROW = 0,
			TFBM_UL_COL = 1,
			TFBM_UR_ROW = 2,
			TFBM_UR_COL = 3,
			TFBM_LL_ROW = 4,
			TFBM_LL_COL = 5,
			TFBM_LR_ROW = 6,
			TFBM_LR_COL = 7,
			TFBM_RANDOM = 8,
			TFBM_MAX = 9,
		};
		ADD_STRUCT(Object::Pointer, ReleaseResourcesFence, 428)
		ADD_STRUCT(float, RenderOffsetV, 424)
		ADD_STRUCT(float, RenderOffsetU, 420)
		ADD_STRUCT(int, CurrentColumn, 416)
		ADD_STRUCT(int, CurrentRow, 412)
		ADD_STRUCT(float, FrameTime, 408)
		ADD_STRUCT(float, FrameRate, 404)
		ADD_STRUCT(TextureFlipBook::TextureFlipBookMethod, FBMethod, 400)
		ADD_STRUCT(Object::Pointer, VfTable_FTickableObject, 368)
		ADD_STRUCT(int, VerticalImages, 396)
		ADD_STRUCT(int, HorizontalImages, 392)
		ADD_BOOL(bAutoPlay, 388, 0x8)
		ADD_BOOL(bLooping, 388, 0x4)
		ADD_BOOL(bStopped, 388, 0x2)
		ADD_BOOL(bPaused, 388, 0x1)
		ADD_STRUCT(float, VerticalScale, 384)
		ADD_STRUCT(float, HorizontalScale, 380)
		ADD_STRUCT(float, TimeSinceLastFrame, 376)
		ADD_STRUCT(float, TimeIntoMovie, 372)
		void Play()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27984);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27985);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Stop()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27986);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCurrentFrame(int Row, int Col)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27987);
			byte params[8] = { NULL };
			*(int*)params = Row;
			*(int*)&params[4] = Col;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
