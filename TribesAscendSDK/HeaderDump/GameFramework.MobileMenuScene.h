#pragma once
#include "GameFramework.MobileMenuObject.h"
#include "Core.Object.h"
#include "GameFramework.MobileInputZone.h"
#include "Engine.Font.h"
#include "Engine.SoundCue.h"
#include "GameFramework.MobilePlayerInput.h"
#include "Engine.Canvas.h"
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
	class MobileMenuScene : public Object
	{
	public:
		ADD_STRUCT(float, Width, 104)
		ADD_STRUCT(float, Height, 108)
		ADD_STRUCT(float, Left, 96)
		ADD_STRUCT(float, Top, 100)
		ADD_STRUCT(float, Opacity, 116)
		ADD_OBJECT(Font, SceneCaptionFont, 84)
		ADD_STRUCT(ScriptArray<class MobileMenuObject*>, MenuObjects, 72)
		ADD_OBJECT(SoundCue, UIUnTouchSound, 124)
		ADD_OBJECT(SoundCue, UITouchSound, 120)
		ADD_STRUCT(float, AuthoredGlobalScale, 112)
		ADD_BOOL(bApplyGlobalScaleHeight, 92, 0x100)
		ADD_BOOL(bApplyGlobalScaleWidth, 92, 0x80)
		ADD_BOOL(bApplyGlobalScaleTop, 92, 0x40)
		ADD_BOOL(bApplyGlobalScaleLeft, 92, 0x20)
		ADD_BOOL(bRelativeHeight, 92, 0x10)
		ADD_BOOL(bRelativeWidth, 92, 0x8)
		ADD_BOOL(bRelativeTop, 92, 0x4)
		ADD_BOOL(bRelativeLeft, 92, 0x2)
		ADD_BOOL(bSceneDoesNotRequireInput, 92, 0x1)
		ADD_OBJECT(MobilePlayerInput, InputOwner, 88)
		ADD_STRUCT(ScriptString*, MenuName, 60)
		float GetGlobalScaleX()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.GetGlobalScaleX");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetGlobalScaleY()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.GetGlobalScaleY");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void InitMenuScene(class MobilePlayerInput* PlayerInput, int ScreenWidth, int ScreenHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.InitMenuScene");
			byte params[12] = { NULL };
			*(class MobilePlayerInput**)&params[0] = PlayerInput;
			*(int*)&params[4] = ScreenWidth;
			*(int*)&params[8] = ScreenHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderScene(class Canvas* Canvas, float RenderDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.RenderScene");
			byte params[8] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(float*)&params[4] = RenderDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnTouch(class MobileMenuObject* Sender, float TouchX, float TouchY, bool bCancel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.OnTouch");
			byte params[16] = { NULL };
			*(class MobileMenuObject**)&params[0] = Sender;
			*(float*)&params[4] = TouchX;
			*(float*)&params[8] = TouchY;
			*(bool*)&params[12] = bCancel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool OnSceneTouch(MobileInputZone::EZoneTouchEvent EventType, float TouchX, float TouchY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.OnSceneTouch");
			byte params[13] = { NULL };
			*(MobileInputZone::EZoneTouchEvent*)&params[0] = EventType;
			*(float*)&params[4] = TouchX;
			*(float*)&params[8] = TouchY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void Opened(ScriptString* Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.Opened");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MadeTopMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.MadeTopMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Closing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.Closing");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Closed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.Closed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanUpScene()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.CleanUpScene");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class MobileMenuObject* FindMenuObject(ScriptString* Tag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.FindMenuObject");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Tag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MobileMenuObject**)&params[12];
		}
		bool MobileMenuCommand(ScriptString* Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.MobileMenuCommand");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
