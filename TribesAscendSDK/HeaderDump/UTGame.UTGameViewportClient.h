#pragma once
#include "Engine.Canvas.h"
#include "UDKBase.UDKGameViewportClient.h"
#include "Engine.PlayerController.h"
#include "Engine.Font.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTGameViewportClient : public UDKGameViewportClient
	{
	public:
		ADD_STRUCT(ScriptString*, LevelActionMessages, 300)
		ADD_STRUCT(ScriptString*, ProgressMessageSceneClassName, 396)
		ADD_OBJECT(Font, LoadingScreenHintMessageFont, 392)
		ADD_OBJECT(Font, LoadingScreenGameTypeNameFont, 388)
		ADD_OBJECT(Font, LoadingScreenMapNameFont, 384)
		ADD_STRUCT(ScriptString*, UTFrontEndString, 372)
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.PostRender");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTransition(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.DrawTransition");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderHeader(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.RenderHeader");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateActiveSplitscreenType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.UpdateActiveSplitscreenType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetProgressMessage(PlayerController::EProgressMessageType MessageType, ScriptString* Message, ScriptString* Title, bool bIgnoreFutureNetworkMessages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.SetProgressMessage");
			byte params[29] = { NULL };
			*(PlayerController::EProgressMessageType*)&params[0] = MessageType;
			*(ScriptString**)&params[4] = Message;
			*(ScriptString**)&params[16] = Title;
			*(bool*)&params[28] = bIgnoreFutureNetworkMessages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyConnectionError(ScriptString* Message, ScriptString* Title)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.NotifyConnectionError");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(ScriptString**)&params[12] = Title;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
