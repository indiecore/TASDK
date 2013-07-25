#pragma once
#include "Engine.UISceneClient.h"
#include "Engine.PlayerController.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Player.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameUISceneClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GameUISceneClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameUISceneClient : public UISceneClient
	{
	public:
		ADD_VAR(::BoolProperty, bCaptureUnprocessedInput, 0x10)
		ADD_VAR(::BoolProperty, bRenderDebugInfo, 0x8)
		ADD_VAR(::BoolProperty, bEnableDebugInput, 0x4)
		ADD_VAR(::BoolProperty, bUpdateSceneViewportSizes, 0x2)
		ADD_VAR(::BoolProperty, bUpdateInputProcessingStatus, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'InitialPressedKeys'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.IntPoint' for the property named 'DoubleClickStartPosition'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'DoubleClickStartTime'!
		ADD_VAR(::FloatProperty, LatestDeltaTime, 0xFFFFFFFF)
		byte GetCurrentNetMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.GetCurrentNetMode");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void RequestInputProcessingUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.RequestInputProcessingUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanUnpauseInternalUI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.CanUnpauseInternalUI");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PauseGame(bool bDesiredPauseState, int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.PauseGame");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bDesiredPauseState;
			*(int*)(params + 4) = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyClientTravel(class PlayerController* TravellingPlayer, ScriptArray<wchar_t> TravelURL, byte TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.NotifyClientTravel");
			byte* params = (byte*)malloc(21);
			*(class PlayerController**)params = TravellingPlayer;
			*(ScriptArray<wchar_t>*)(params + 4) = TravelURL;
			*(params + 16) = TravelType;
			*(bool*)(params + 20) = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.NotifyGameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.NotifyPlayerAdded");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.NotifyPlayerRemoved");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int FindLocalPlayerIndex(class Player* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameUISceneClient.FindLocalPlayerIndex");
			byte* params = (byte*)malloc(8);
			*(class Player**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
