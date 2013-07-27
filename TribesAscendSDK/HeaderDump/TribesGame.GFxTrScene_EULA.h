#pragma once
#include "TribesGame.GFxTrScene.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxTrScene_EULA : public GFxTrScene
	{
	public:
		ADD_STRUCT(ScriptString*, EULA, 132)
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAccepted;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
