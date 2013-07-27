#pragma once
#include "Core.Object.h"
#include "Engine.Console.h"
#include "Engine.Canvas.h"
#include "Engine.UIInteraction.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Interaction.h"
#include "Engine.PlayerController.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameViewportClient : public Object
	{
	public:
		enum ESplitScreenType : byte
		{
			eSST_NONE = 0,
			eSST_2P_HORIZONTAL = 1,
			eSST_2P_VERTICAL = 2,
			eSST_3P_FAVOR_TOP = 3,
			eSST_3P_FAVOR_BOTTOM = 4,
			eSST_4P = 5,
			eSST_MAX = 6,
		};
		enum ESafeZoneType : byte
		{
			eSZ_TOP = 0,
			eSZ_BOTTOM = 1,
			eSZ_LEFT = 2,
			eSZ_RIGHT = 3,
			eSZ_MAX = 4,
		};
		struct TitleSafeZoneArea
		{
		public:
			ADD_STRUCT(float, MaxPercentX, 0)
			ADD_STRUCT(float, RecommendedPercentX, 8)
			ADD_STRUCT(float, MaxPercentY, 4)
			ADD_STRUCT(float, RecommendedPercentY, 12)
		};
		struct PerPlayerSplitscreenData
		{
		public:
			ADD_STRUCT(float, OriginY, 12)
			ADD_STRUCT(float, OriginX, 8)
			ADD_STRUCT(float, SizeY, 4)
			ADD_STRUCT(float, SizeX, 0)
		};
		struct SplitscreenData
		{
		public:
			ADD_STRUCT(ScriptArray<GameViewportClient::PerPlayerSplitscreenData>, PlayerData, 0)
		};
		struct DebugDisplayProperty
		{
		public:
			ADD_BOOL(bSpecialProperty, 12, 0x1)
			ADD_STRUCT(ScriptName, PropertyName, 4)
			ADD_OBJECT(Object, Obj, 0)
		};
		ADD_OBJECT(Console, ViewportConsole, 96)
		ADD_OBJECT(UIInteraction, UIController, 92)
		ADD_STRUCT(GameViewportClient::ESplitScreenType, ActiveSplitscreenType, 201)
		ADD_STRUCT(GameViewportClient::ESplitScreenType, DesiredSplitscreenType, 200)
		ADD_OBJECT(ScriptClass, UIControllerClass, 88)
		ADD_BOOL(bDebugNoGFxUI, 168, 0x80)
		ADD_STRUCT(ScriptArray<class Interaction*>, GlobalInteractions, 76)
		ADD_STRUCT(GameViewportClient::ESplitScreenType, Default2PSplitType, 202)
		ADD_STRUCT(GameViewportClient::ESplitScreenType, Default3PSplitType, 203)
		ADD_STRUCT(ScriptArray<GameViewportClient::SplitscreenData>, SplitscreenInfo, 188)
		ADD_STRUCT(GameViewportClient::TitleSafeZoneArea, TitleSafeZone, 172)
		ADD_BOOL(bShowTitleSafeZone, 168, 0x1)
		ADD_STRUCT(float, ProgressTimeOut, 228)
		ADD_STRUCT(float, ProgressFadeTime, 232)
		ADD_STRUCT(ScriptString*, ProgressMessage, 204)
		ADD_STRUCT(ScriptString*, LoadingMessage, 108)
		ADD_STRUCT(ScriptString*, SavingMessage, 120)
		ADD_STRUCT(ScriptString*, ConnectingMessage, 132)
		ADD_STRUCT(ScriptString*, PrecachingMessage, 156)
		ADD_STRUCT(ScriptString*, PausedMessage, 144)
		ADD_STRUCT(Object::Pointer, VfTable_FViewportClient, 60)
		ADD_STRUCT(Object::Pointer, VfTable_FExec, 64)
		ADD_STRUCT(Object::Pointer, Viewport, 68)
		ADD_STRUCT(Object::Pointer, ViewportFrame, 72)
		ADD_STRUCT(QWord, ShowFlags, 100)
		ADD_BOOL(bDisplayingUIMouseCursor, 168, 0x2)
		ADD_BOOL(bUIMouseCaptureOverride, 168, 0x4)
		ADD_BOOL(bOverrideDiffuseAndSpecular, 168, 0x8)
		ADD_BOOL(bIsPlayInEditorViewport, 168, 0x10)
		ADD_BOOL(bShowSystemMouseCursor, 168, 0x20)
		ADD_BOOL(bDisableWorldRendering, 168, 0x40)
		ADD_BOOL(bUseHardwareCursorWhenWindowed, 168, 0x100)
		ADD_STRUCT(ScriptArray<GameViewportClient::DebugDisplayProperty>, DebugProperties, 236)
		ADD_STRUCT(Object::Pointer, ScaleformInteraction, 248)
		ScriptString* ConsoleCommand(ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12994);
			byte params[24] = { NULL };
			*(ScriptString**)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		bool HandleInputKey(int ControllerId, ScriptName Key, Object::EInputEvent EventType, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17875);
			byte params[25] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = EventType;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool HandleInputAxis(int ControllerId, ScriptName Key, float Delta, float DeltaTime, bool bGamepad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17882);
			byte params[28] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(float*)&params[12] = Delta;
			*(float*)&params[16] = DeltaTime;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool HandleInputChar(int ControllerId, ScriptString* Unicode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17889);
			byte params[20] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptString**)&params[4] = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void GetViewportSize(Object::Vector2D& out_ViewportSize)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17894);
			byte params[8] = { NULL };
			*(Object::Vector2D*)params = out_ViewportSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewportSize = *(Object::Vector2D*)params;
		}
		bool IsFullScreenViewport()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17896);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ShouldForceFullscreenViewport()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17898);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetNumCustomInteractions()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17900);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		ScriptClass* GetCustomInteractionClass(int InIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17902);
			byte params[8] = { NULL };
			*(int*)params = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		void SetCustomInteractionObject(class Interaction* InInteraction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17905);
			byte params[4] = { NULL };
			*(class Interaction**)params = InInteraction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class LocalPlayer* CreatePlayer(int ControllerId, ScriptString*& OutError, bool bSpawnActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17907);
			byte params[24] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptString**)&params[4] = OutError;
			*(bool*)&params[16] = bSpawnActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)&params[4];
			return *(class LocalPlayer**)&params[20];
		}
		int AddLocalPlayer(class LocalPlayer* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17914);
			byte params[8] = { NULL };
			*(class LocalPlayer**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int RemoveLocalPlayer(class LocalPlayer* ExistingPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17917);
			byte params[8] = { NULL };
			*(class LocalPlayer**)params = ExistingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17919);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)&params[4] = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RemovePlayer(class LocalPlayer* ExPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17920);
			byte params[8] = { NULL };
			*(class LocalPlayer**)params = ExPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17924);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)&params[4] = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class LocalPlayer* FindPlayerByControllerId(int ControllerId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17925);
			byte params[8] = { NULL };
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class LocalPlayer**)&params[4];
		}
		bool CreateViewportConsole(ScriptClass* vpcClass, ScriptString*& OutError)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17929);
			byte params[20] = { NULL };
			*(ScriptClass**)params = vpcClass;
			*(ScriptString**)&params[4] = OutError;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		bool Init(ScriptString*& OutError)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17933);
			byte params[16] = { NULL };
			*(ScriptString**)params = OutError;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)params;
			return *(bool*)&params[12];
		}
		bool CreateInitialPlayer(ScriptString*& OutError)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17945);
			byte params[16] = { NULL };
			*(ScriptString**)params = OutError;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)params;
			return *(bool*)&params[12];
		}
		int InsertInteraction(class Interaction* NewInteraction, int InIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17955);
			byte params[12] = { NULL };
			*(class Interaction**)params = NewInteraction;
			*(int*)&params[4] = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void GameSessionEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17961);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSplitscreenConfiguration(GameViewportClient::ESplitScreenType SplitType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17963);
			byte params[1] = { NULL };
			*(GameViewportClient::ESplitScreenType*)params = SplitType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GameViewportClient::ESplitScreenType GetSplitscreenConfiguration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17965);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GameViewportClient::ESplitScreenType*)params;
		}
		void UpdateActiveSplitscreenType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17967);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LayoutPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17971);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetSubtitleRegion(Object::Vector2D& MinPos, Object::Vector2D& MaxPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17977);
			byte params[16] = { NULL };
			*(Object::Vector2D*)params = MinPos;
			*(Object::Vector2D*)&params[8] = MaxPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MinPos = *(Object::Vector2D*)params;
			MaxPos = *(Object::Vector2D*)&params[8];
		}
		int ConvertLocalPlayerToGamePlayerIndex(class LocalPlayer* LPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17980);
			byte params[8] = { NULL };
			*(class LocalPlayer**)params = LPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool HasTopSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17983);
			byte params[8] = { NULL };
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasBottomSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17986);
			byte params[8] = { NULL };
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasLeftSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17989);
			byte params[8] = { NULL };
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasRightSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17992);
			byte params[8] = { NULL };
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetPixelSizeOfScreen(float& out_Width, float& out_Height, class Canvas* Canvas, int LocalPlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17995);
			byte params[16] = { NULL };
			*(float*)params = out_Width;
			*(float*)&params[4] = out_Height;
			*(class Canvas**)&params[8] = Canvas;
			*(int*)&params[12] = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Width = *(float*)params;
			out_Height = *(float*)&params[4];
		}
		void CalculateSafeZoneValues(float& out_Horizontal, float& out_Vertical, class Canvas* Canvas, int LocalPlayerIndex, bool bUseMaxPercent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18000);
			byte params[20] = { NULL };
			*(float*)params = out_Horizontal;
			*(float*)&params[4] = out_Vertical;
			*(class Canvas**)&params[8] = Canvas;
			*(int*)&params[12] = LocalPlayerIndex;
			*(bool*)&params[16] = bUseMaxPercent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Horizontal = *(float*)params;
			out_Vertical = *(float*)&params[4];
		}
		bool CalculateDeadZoneForAllSides(class LocalPlayer* LPlayer, class Canvas* Canvas, float& fTopSafeZone, float& fBottomSafeZone, float& fLeftSafeZone, float& fRightSafeZone, bool bUseMaxPercent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18015);
			byte params[32] = { NULL };
			*(class LocalPlayer**)params = LPlayer;
			*(class Canvas**)&params[4] = Canvas;
			*(float*)&params[8] = fTopSafeZone;
			*(float*)&params[12] = fBottomSafeZone;
			*(float*)&params[16] = fLeftSafeZone;
			*(float*)&params[20] = fRightSafeZone;
			*(bool*)&params[24] = bUseMaxPercent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			fTopSafeZone = *(float*)&params[8];
			fBottomSafeZone = *(float*)&params[12];
			fLeftSafeZone = *(float*)&params[16];
			fRightSafeZone = *(float*)&params[20];
			return *(bool*)&params[28];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18031);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTitleSafeArea(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18033);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18035);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayProgressMessage(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18038);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTransition(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18051);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTransitionMessage(class Canvas* Canvas, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18058);
			byte params[16] = { NULL };
			*(class Canvas**)params = Canvas;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetProgressMessage(PlayerController::EProgressMessageType MessageType, ScriptString* Message, ScriptString* Title, bool bIgnoreFutureNetworkMessages)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18075);
			byte params[29] = { NULL };
			*(PlayerController::EProgressMessageType*)params = MessageType;
			*(ScriptString**)&params[4] = Message;
			*(ScriptString**)&params[16] = Title;
			*(bool*)&params[28] = bIgnoreFutureNetworkMessages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyConnectionError(ScriptString* Message, ScriptString* Title)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18081);
			byte params[24] = { NULL };
			*(ScriptString**)params = Message;
			*(ScriptString**)&params[12] = Title;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetProgressTime(float T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18085);
			byte params[4] = { NULL };
			*(float*)params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearProgressMessages()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18087);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class LocalPlayer* GetPlayerOwner(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18089);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class LocalPlayer**)&params[4];
		}
		void FixupOwnerReferences()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18092);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPrimaryPlayerSwitch(class LocalPlayer* OldPrimaryPlayer, class LocalPlayer* NewPrimaryPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18093);
			byte params[8] = { NULL };
			*(class LocalPlayer**)params = OldPrimaryPlayer;
			*(class LocalPlayer**)&params[4] = NewPrimaryPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BecomePrimaryPlayer(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18096);
			byte params[4] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DebugSetUISystemEnabled(bool bOldUISystemActive, bool bGFxUISystemActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18105);
			byte params[8] = { NULL };
			*(bool*)params = bOldUISystemActive;
			*(bool*)&params[4] = bGFxUISystemActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
