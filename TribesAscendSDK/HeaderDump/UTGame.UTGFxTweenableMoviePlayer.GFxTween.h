#pragma once
#include "GFxUI.GFxObject.ASDisplayInfo.h"
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGFxTweenableMoviePlayer.GFxTween." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGFxTweenableMoviePlayer.GFxTween." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGFxTweenableMoviePlayer.GFxTween." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTween
	{
	public:
		ADD_VAR(::ByteProperty, ThisTweenType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFinished, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<ASDisplayInfo>, displayInfo, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Callback, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MemberName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Delta, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TweenTime, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, TargetMC)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
