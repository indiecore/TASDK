#pragma once
#include "Engine.UISceneClient.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.WorldInfo.h"
#include "Engine.PlayerController.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Player.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GameUISceneClient : public UISceneClient
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, NavAliases, 300)
		ADD_STRUCT(ScriptArray<ScriptName>, AxisInputKeys, 312)
		ADD_BOOL(bCaptureUnprocessedInput, 296, 0x10)
		ADD_BOOL(bRenderDebugInfo, 296, 0x8)
		ADD_BOOL(bEnableDebugInput, 296, 0x4)
		ADD_BOOL(bUpdateSceneViewportSizes, 296, 0x2)
		ADD_BOOL(bUpdateInputProcessingStatus, 296, 0x1)
		ADD_STRUCT(Object::Map_Mirror, InitialPressedKeys, 236)
		ADD_STRUCT(Object::IntPoint, DoubleClickStartPosition, 228)
		ADD_STRUCT(Object::Double, DoubleClickStartTime, 220)
		ADD_STRUCT(float, LatestDeltaTime, 216)
		WorldInfo::ENetMode GetCurrentNetMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17834);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(WorldInfo::ENetMode*)params;
		}
		void RequestInputProcessingUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17836);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanUnpauseInternalUI()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17837);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PauseGame(bool bDesiredPauseState, int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17839);
			byte params[8] = { NULL };
			*(bool*)params = bDesiredPauseState;
			*(int*)&params[4] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyClientTravel(class PlayerController* TravellingPlayer, ScriptString* TravelURL, Actor::ETravelType TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17843);
			byte params[21] = { NULL };
			*(class PlayerController**)params = TravellingPlayer;
			*(ScriptString**)&params[4] = TravelURL;
			*(Actor::ETravelType*)&params[16] = TravelType;
			*(bool*)&params[20] = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17848);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17849);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)&params[4] = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17852);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)&params[4] = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int FindLocalPlayerIndex(class Player* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17855);
			byte params[8] = { NULL };
			*(class Player**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
