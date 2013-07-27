#pragma once
#include "Engine.UIRoot.h"
#include "Core.Object.h"
#include "Engine.Canvas.h"
#include "Engine.LocalPlayer.h"
namespace UnrealScript
{
	class Interaction : public UIRoot
	{
	public:
		bool OnReceivedNativeInputKey(int ControllerId, ScriptName Key, Object::EInputEvent EventType, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.OnReceivedNativeInputKey");
			byte params[25] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = EventType;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void OnInitialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.OnInitialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool OnReceivedNativeInputChar(int ControllerId, ScriptString* Unicode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.OnReceivedNativeInputChar");
			byte params[20] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptString**)&params[4] = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool OnReceivedNativeInputAxis(int ControllerId, ScriptName Key, float Delta, float DeltaTime, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.OnReceivedNativeInputAxis");
			byte params[28] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(float*)&params[12] = Delta;
			*(float*)&params[16] = DeltaTime;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.PostRender");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialized()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.Initialized");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.NotifyGameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.NotifyPlayerAdded");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			*(class LocalPlayer**)&params[4] = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.NotifyPlayerRemoved");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			*(class LocalPlayer**)&params[4] = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
