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
		// Here lies the not-yet-implemented method 'GetGlobalScaleX'
		// Here lies the not-yet-implemented method 'GetGlobalScaleY'
		// Here lies the not-yet-implemented method 'InitMenuScene'
		// Here lies the not-yet-implemented method 'RenderScene'
		// Here lies the not-yet-implemented method 'OnTouch'
		// Here lies the not-yet-implemented method 'OnSceneTouch'
		// Here lies the not-yet-implemented method 'Opened'
		// Here lies the not-yet-implemented method 'MadeTopMenu'
		// Here lies the not-yet-implemented method 'Closing'
		// Here lies the not-yet-implemented method 'Closed'
		// Here lies the not-yet-implemented method 'CleanUpScene'
		// Here lies the not-yet-implemented method 'FindMenuObject'
		// Here lies the not-yet-implemented method 'MobileMenuCommand'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
