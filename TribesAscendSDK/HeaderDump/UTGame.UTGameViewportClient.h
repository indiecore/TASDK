#pragma once
#include "Engine.Canvas.h"
#include "UDKBase.UDKGameViewportClient.h"
#include "Engine.Font.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGameViewportClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTGameViewportClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTGameViewportClient : public UDKGameViewportClient
	{
	public:
		ADD_VAR(::StrProperty, LevelActionMessages, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProgressMessageSceneClassName, 0xFFFFFFFF)
		ADD_OBJECT(Font, LoadingScreenHintMessageFont)
		ADD_OBJECT(Font, LoadingScreenGameTypeNameFont)
		ADD_OBJECT(Font, LoadingScreenMapNameFont)
		ADD_VAR(::StrProperty, UTFrontEndString, 0xFFFFFFFF)
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.PostRender");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTransition(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.DrawTransition");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderHeader(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.RenderHeader");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateActiveSplitscreenType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.UpdateActiveSplitscreenType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetProgressMessage(byte MessageType, ScriptArray<wchar_t> Message, ScriptArray<wchar_t> Title, bool bIgnoreFutureNetworkMessages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.SetProgressMessage");
			byte* params = (byte*)malloc(29);
			*params = MessageType;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			*(ScriptArray<wchar_t>*)(params + 16) = Title;
			*(bool*)(params + 28) = bIgnoreFutureNetworkMessages;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyConnectionError(ScriptArray<wchar_t> Message, ScriptArray<wchar_t> Title)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameViewportClient.NotifyConnectionError");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Message;
			*(ScriptArray<wchar_t>*)(params + 12) = Title;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
