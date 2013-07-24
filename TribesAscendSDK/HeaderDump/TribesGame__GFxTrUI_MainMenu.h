#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrUI_MainMenu." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrUI_MainMenu : public GFxUI_PauseMenu
	{
	public:
		ADD_OBJECT(GFxUI_PauseMenu, FamilyMenuMovie)
	};
}
#undef ADD_OBJECT
