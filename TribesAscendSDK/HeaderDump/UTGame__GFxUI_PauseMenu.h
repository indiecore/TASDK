#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUI_PauseMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUI_PauseMenu." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUI_PauseMenu : public UTGFxTweenableMoviePlayer
	{
	public:
		ADD_VAR(::StrProperty, ExitString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ResumeString, 0xFFFFFFFF)
		ADD_OBJECT(GFxClikWidget, Btn_ExitMC)
		ADD_OBJECT(GFxClikWidget, Btn_ResumeMC)
		ADD_OBJECT(GFxObject, Btn_Family_Wrapper)
		ADD_OBJECT(GFxObject, Btn_Exit_Wrapper)
		ADD_OBJECT(GFxObject, Btn_Resume_Wrapper)
		ADD_OBJECT(GFxObject, OverlayMC)
		ADD_OBJECT(GFxObject, PauseMC)
		ADD_OBJECT(GFxObject, RootMC)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
