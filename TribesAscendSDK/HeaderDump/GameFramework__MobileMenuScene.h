#pragma once
#include "Engine__SoundCue.h"
#include "Core__Object.h"
#include "Engine__Canvas.h"
#include "Engine__Font.h"
#include "GameFramework__MobilePlayerInput.h"
#include "GameFramework__MobileMenuObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobileMenuScene." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileMenuScene." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileMenuScene : public Object
	{
	public:
		ADD_VAR(::FloatProperty, Width, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Height, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Left, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Top, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Opacity, 0xFFFFFFFF)
		ADD_OBJECT(Font, SceneCaptionFont)
		ADD_OBJECT(SoundCue, UIUnTouchSound)
		ADD_OBJECT(SoundCue, UITouchSound)
		ADD_VAR(::FloatProperty, AuthoredGlobalScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bApplyGlobalScaleHeight, 0x100)
		ADD_VAR(::BoolProperty, bApplyGlobalScaleWidth, 0x80)
		ADD_VAR(::BoolProperty, bApplyGlobalScaleTop, 0x40)
		ADD_VAR(::BoolProperty, bApplyGlobalScaleLeft, 0x20)
		ADD_VAR(::BoolProperty, bRelativeHeight, 0x10)
		ADD_VAR(::BoolProperty, bRelativeWidth, 0x8)
		ADD_VAR(::BoolProperty, bRelativeTop, 0x4)
		ADD_VAR(::BoolProperty, bRelativeLeft, 0x2)
		ADD_VAR(::BoolProperty, bSceneDoesNotRequireInput, 0x1)
		ADD_OBJECT(MobilePlayerInput, InputOwner)
		ADD_VAR(::StrProperty, MenuName, 0xFFFFFFFF)
		float GetGlobalScaleX()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.GetGlobalScaleX");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetGlobalScaleY()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.GetGlobalScaleY");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void InitMenuScene(class MobilePlayerInput* PlayerInput, int ScreenWidth, int ScreenHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.InitMenuScene");
			byte* params = (byte*)malloc(12);
			*(class MobilePlayerInput**)params = PlayerInput;
			*(int*)(params + 4) = ScreenWidth;
			*(int*)(params + 8) = ScreenHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderScene(class Canvas* Canvas, float RenderDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.RenderScene");
			byte* params = (byte*)malloc(8);
			*(class Canvas**)params = Canvas;
			*(float*)(params + 4) = RenderDelta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnTouch(class MobileMenuObject* Sender, float TouchX, float TouchY, bool bCancel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.OnTouch");
			byte* params = (byte*)malloc(16);
			*(class MobileMenuObject**)params = Sender;
			*(float*)(params + 4) = TouchX;
			*(float*)(params + 8) = TouchY;
			*(bool*)(params + 12) = bCancel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool OnSceneTouch(byte EventType, float TouchX, float TouchY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.OnSceneTouch");
			byte* params = (byte*)malloc(13);
			*params = EventType;
			*(float*)(params + 4) = TouchX;
			*(float*)(params + 8) = TouchY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void Opened(ScriptArray<wchar_t> Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.Opened");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MadeTopMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.MadeTopMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Closing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.Closing");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
		class MobileMenuObject* FindMenuObject(ScriptArray<wchar_t> Tag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.FindMenuObject");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Tag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MobileMenuObject**)(params + 12);
			free(params);
			return returnVal;
		}
		bool MobileMenuCommand(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuScene.MobileMenuCommand");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
