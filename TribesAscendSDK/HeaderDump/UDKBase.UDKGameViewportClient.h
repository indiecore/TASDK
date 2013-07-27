#pragma once
#include "Engine.GameViewportClient.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKGameViewportClient : public GameViewportClient
	{
	public:
		ADD_STRUCT(ScriptString*, HintLocFileName, 288)
		ScriptString* LoadRandomLocalizedHintMessage(ScriptString* Category1Name, ScriptString* Category2Name)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameViewportClient.LoadRandomLocalizedHintMessage");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = Category1Name;
			*(ScriptString**)&params[12] = Category2Name;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
	};
}
#undef ADD_STRUCT
