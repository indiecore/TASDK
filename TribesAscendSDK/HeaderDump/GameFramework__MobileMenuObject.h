#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobileMenuObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileMenuObject." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileMenuObject : public Object
	{
	public:
		ADD_OBJECT(MobileMenuScene, OwnerScene)
		ADD_VAR(::FloatProperty, Opacity, 0xFFFFFFFF)
		ADD_OBJECT(MobilePlayerInput, InputOwner)
		ADD_VAR(::StrProperty, Tag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, YOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, XOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RightLeeway, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftLeeway, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BottomLeeway, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TopLeeway, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AuthoredGlobalScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Height, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Width, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Top, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Left, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsHighlighted, 0x8000)
		ADD_VAR(::BoolProperty, bIsTouched, 0x4000)
		ADD_VAR(::BoolProperty, bIsHidden, 0x2000)
		ADD_VAR(::BoolProperty, bIsActive, 0x1000)
		ADD_VAR(::BoolProperty, bYOffsetIsActual, 0x800)
		ADD_VAR(::BoolProperty, bXOffsetIsActual, 0x400)
		ADD_VAR(::BoolProperty, bHeightRelativeToWidth, 0x200)
		ADD_VAR(::BoolProperty, bApplyGlobalScaleHeight, 0x100)
		ADD_VAR(::BoolProperty, bApplyGlobalScaleWidth, 0x80)
		ADD_VAR(::BoolProperty, bApplyGlobalScaleTop, 0x40)
		ADD_VAR(::BoolProperty, bApplyGlobalScaleLeft, 0x20)
		ADD_VAR(::BoolProperty, bRelativeHeight, 0x10)
		ADD_VAR(::BoolProperty, bRelativeWidth, 0x8)
		ADD_VAR(::BoolProperty, bRelativeTop, 0x4)
		ADD_VAR(::BoolProperty, bRelativeLeft, 0x2)
		ADD_VAR(::BoolProperty, bHasBeenInitialized, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
