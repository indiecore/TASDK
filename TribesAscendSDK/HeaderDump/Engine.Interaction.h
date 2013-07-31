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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12902);
			byte params[25] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = EventType;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void OnInitialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12910);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool OnReceivedNativeInputChar(int ControllerId, ScriptString* Unicode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12912);
			byte params[20] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptString**)&params[4] = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool OnReceivedNativeInputAxis(int ControllerId, ScriptName Key, float Delta, float DeltaTime, bool bGamepad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12914);
			byte params[28] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(float*)&params[12] = Delta;
			*(float*)&params[16] = DeltaTime;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12925);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12927);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12929);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialized()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12930);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12931);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12932);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)&params[4] = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12935);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)&params[4] = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
