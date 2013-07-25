#pragma once
#include "UTGame__UTGFxTweenableMoviePlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxProjectedUI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.GFxProjectedUI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxProjectedUI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxProjectedUI : public UTGFxTweenableMoviePlayer
	{
	public:
		ADD_VAR(::StrProperty, CancelString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AcceptString, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, StartRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, leftThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, rightThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, rotval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Height, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Width, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scale, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, InfoTitle)
		ADD_OBJECT(GFxObject, InfoText)
		ADD_OBJECT(GFxObject, InfoIconItem)
		ADD_OBJECT(GFxObject, InfoIconWeap)
		ADD_OBJECT(GFxObject, InfoMC)
		ADD_OBJECT(GFxObject, BG_Edge_RightBottom)
		ADD_OBJECT(GFxObject, BG_Edge_RightMiddle)
		ADD_OBJECT(GFxObject, BG_Edge_RightTop)
		ADD_OBJECT(GFxObject, BG_Edge_LeftTop)
		ADD_OBJECT(GFxObject, BG_Edge_LeftMiddle)
		ADD_OBJECT(GFxObject, BG_Edge_LeftBottom)
		ADD_OBJECT(GFxObject, BG_Optic4MC)
		ADD_OBJECT(GFxObject, BG_Optic3MC)
		ADD_OBJECT(GFxObject, BG_Optic2MC)
		ADD_OBJECT(GFxObject, BG_Optic1MC)
		ADD_OBJECT(GFxObject, BG_ArrowMC)
		ADD_OBJECT(GFxObject, BG_LineMC)
		ADD_OBJECT(GFxObject, StartUpTextMC)
		ADD_OBJECT(GFxObject, CPCLogoMC)
		ADD_OBJECT(GFxObject, BackgroundMC)
		ADD_OBJECT(GFxObject, LeftArrow01)
		ADD_OBJECT(GFxObject, LeftArrow02)
		ADD_OBJECT(GFxObject, ArsenalTabMC)
		ADD_OBJECT(GFxObject, BackpackTabMC)
		ADD_VAR(::BoolProperty, bInitialized, 0x2)
		ADD_VAR(::BoolProperty, bArsenalTabFocused, 0x1)
		ADD_OBJECT(GFxObject, EquippedWeaponText2)
		ADD_OBJECT(GFxObject, EquippedWeaponText1)
		ADD_OBJECT(GFxObject, EquippedWeaponOutline)
		ADD_OBJECT(GFxObject, EquippedWeapon)
		ADD_OBJECT(GFxObject, ArsenalMC)
		ADD_OBJECT(GFxObject, BackpackMC)
		ADD_OBJECT(GFxObject, MainMC)
		ADD_OBJECT(GFxObject, Window)
		ADD_OBJECT(GFxObject, Root)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
