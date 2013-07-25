#pragma once
#include "UTGame__GFxUI_PauseMenu.h"
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
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_MainMenu.Start");
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
