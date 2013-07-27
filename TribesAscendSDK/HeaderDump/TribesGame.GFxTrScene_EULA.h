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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63265);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AcceptEULA()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63266);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63267);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EULAReponse(bool bAccepted)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63268);
			byte params[4] = { NULL };
			*(bool*)params = bAccepted;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
