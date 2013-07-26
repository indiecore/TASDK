#pragma once
#include "Engine.UISoundTheme.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxMoviePlayer.SoundThemeBinding." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxMoviePlayer.SoundThemeBinding." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SoundThemeBinding
	{
	public:
		ADD_VAR(::NameProperty, ThemeName, 0xFFFFFFFF)
		ADD_OBJECT(UISoundTheme, Theme)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
