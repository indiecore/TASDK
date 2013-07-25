#pragma once
#include "TribesGame.GFxTrScene.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrScene_EULA." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrScene_EULA : public GFxTrScene
	{
	public:
		ADD_VAR(::StrProperty, EULA, 0xFFFFFFFF)
		void LoadEULA()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_EULA.LoadEULA");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AcceptEULA()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_EULA.AcceptEULA");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_EULA.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EULAReponse(bool bAccepted)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_EULA.EULAReponse");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAccepted;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
