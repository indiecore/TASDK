#pragma once
#include "GFxUI__GFxMoviePlayer.h"
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUI.GFxAction_CloseMovie." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxUI.GFxAction_CloseMovie." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxAction_CloseMovie : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bUnload, 0x1)
		ADD_OBJECT(GFxMoviePlayer, Movie)
		bool IsValidLevelSequenceObject()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxAction_CloseMovie.IsValidLevelSequenceObject");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
