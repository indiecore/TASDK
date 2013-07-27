#pragma once
#include "Core.Object.h"
#include "Engine.Canvas.h"
#include "GameFramework.MobileMenuScene.h"
#include "GameFramework.MobilePlayerInput.h"
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
	class MobileMenuObject : public Object
	{
	public:
		struct UVCoords
		{
		public:
			ADD_STRUCT(float, VL, 16)
			ADD_STRUCT(float, UL, 12)
			ADD_STRUCT(float, V, 8)
			ADD_STRUCT(float, U, 4)
			ADD_BOOL(bCustomCoords, 0, 0x1)
		};
		ADD_OBJECT(MobileMenuScene, OwnerScene, 128)
		ADD_STRUCT(float, Opacity, 124)
		ADD_OBJECT(MobilePlayerInput, InputOwner, 120)
		ADD_STRUCT(ScriptString*, Tag, 108)
		ADD_STRUCT(float, YOffset, 104)
		ADD_STRUCT(float, XOffset, 100)
		ADD_STRUCT(float, RightLeeway, 96)
		ADD_STRUCT(float, LeftLeeway, 92)
		ADD_STRUCT(float, BottomLeeway, 88)
		ADD_STRUCT(float, TopLeeway, 84)
		ADD_STRUCT(float, AuthoredGlobalScale, 80)
		ADD_STRUCT(float, Height, 76)
		ADD_STRUCT(float, Width, 72)
		ADD_STRUCT(float, Top, 68)
		ADD_STRUCT(float, Left, 64)
		ADD_BOOL(bIsHighlighted, 60, 0x8000)
		ADD_BOOL(bIsTouched, 60, 0x4000)
		ADD_BOOL(bIsHidden, 60, 0x2000)
		ADD_BOOL(bIsActive, 60, 0x1000)
		ADD_BOOL(bYOffsetIsActual, 60, 0x800)
		ADD_BOOL(bXOffsetIsActual, 60, 0x400)
		ADD_BOOL(bHeightRelativeToWidth, 60, 0x200)
		ADD_BOOL(bApplyGlobalScaleHeight, 60, 0x100)
		ADD_BOOL(bApplyGlobalScaleWidth, 60, 0x80)
		ADD_BOOL(bApplyGlobalScaleTop, 60, 0x40)
		ADD_BOOL(bApplyGlobalScaleLeft, 60, 0x20)
		ADD_BOOL(bRelativeHeight, 60, 0x10)
		ADD_BOOL(bRelativeWidth, 60, 0x8)
		ADD_BOOL(bRelativeTop, 60, 0x4)
		ADD_BOOL(bRelativeLeft, 60, 0x2)
		ADD_BOOL(bHasBeenInitialized, 60, 0x1)
		void InitMenuObject(class MobilePlayerInput* PlayerInput, class MobileMenuScene* Scene, int ScreenWidth, int ScreenHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32587);
			byte params[16] = { NULL };
			*(class MobilePlayerInput**)params = PlayerInput;
			*(class MobileMenuScene**)&params[4] = Scene;
			*(int*)&params[8] = ScreenWidth;
			*(int*)&params[12] = ScreenHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderObject(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32604);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
