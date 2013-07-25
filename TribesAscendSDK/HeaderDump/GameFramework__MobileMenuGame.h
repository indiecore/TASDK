#pragma once
#include "Engine__GameInfo.h"
#include "Engine__PlayerController.h"
#include "Engine__Controller.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileMenuGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileMenuGame : public GameInfo
	{
	public:
		ADD_OBJECT(ScriptClass, InitialSceneToDisplayClass)
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuGame.PostLogin");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuGame.StartMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestartPlayer(class Controller* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuGame.RestartPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
