#pragma once
#include "Engine.UIRoot.h"
#include "Engine.Canvas.h"
#include "Engine.LocalPlayer.h"
namespace UnrealScript
{
	class Interaction : public UIRoot
	{
	public:
		bool OnReceivedNativeInputKey(int ControllerId, ScriptName Key, byte EventType, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.OnReceivedNativeInputKey");
			byte* params = (byte*)malloc(25);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = Key;
			*(params + 12) = EventType;
			*(float*)(params + 16) = AmountDepressed;
			*(bool*)(params + 20) = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void OnInitialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.OnInitialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool OnReceivedNativeInputChar(int ControllerId, ScriptArray<wchar_t> Unicode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.OnReceivedNativeInputChar");
			byte* params = (byte*)malloc(20);
			*(int*)params = ControllerId;
			*(ScriptArray<wchar_t>*)(params + 4) = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool OnReceivedNativeInputAxis(int ControllerId, ScriptName Key, float Delta, float DeltaTime, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.OnReceivedNativeInputAxis");
			byte* params = (byte*)malloc(28);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = Key;
			*(float*)(params + 12) = Delta;
			*(float*)(params + 16) = DeltaTime;
			*(bool*)(params + 20) = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.PostRender");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interaction.NotifyPlayerRemoved");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
