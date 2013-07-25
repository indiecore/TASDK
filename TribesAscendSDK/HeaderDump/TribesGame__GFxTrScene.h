#pragma once
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrMenuMoviePlayer.h"
#include "Engine__OnlineSubsystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrScene." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrScene." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrScene : public GFxObject
	{
	public:
		ADD_OBJECT(GFxTrMenuMoviePlayer, TrOuter)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_VAR(::BoolProperty, bSceneCreated, 0x1)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
