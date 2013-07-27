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
		class TitleSafeZoneArea
		{
		public:
			ADD_STRUCT(float, MaxPercentX, 0)
			ADD_STRUCT(float, RecommendedPercentX, 8)
			ADD_STRUCT(float, MaxPercentY, 4)
			ADD_STRUCT(float, RecommendedPercentY, 12)
		};
		class PerPlayerSplitscreenData
		{
		public:
			ADD_STRUCT(float, OriginY, 12)
			ADD_STRUCT(float, OriginX, 8)
			ADD_STRUCT(float, SizeY, 4)
			ADD_STRUCT(float, SizeX, 0)
		};
		class SplitscreenData
		{
		public:
			ADD_STRUCT(ScriptArray<GameViewportClient::PerPlayerSplitscreenData>, PlayerData, 0)
		};
		class DebugDisplayProperty
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
		ADD_STRUCT(Object::QWord, ShowFlags, 100)
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.ConsoleCommand");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		bool HandleInputKey(int ControllerId, ScriptName Key, Object::EInputEvent EventType, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HandleInputKey");
			byte params[25] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = EventType;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool HandleInputAxis(int ControllerId, ScriptName Key, float Delta, float DeltaTime, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HandleInputAxis");
			byte params[28] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(float*)&params[12] = Delta;
			*(float*)&params[16] = DeltaTime;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool HandleInputChar(int ControllerId, ScriptString* Unicode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HandleInputChar");
			byte params[20] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptString**)&params[4] = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void GetViewportSize(Object::Vector2D& out_ViewportSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetViewportSize");
			byte params[8] = { NULL };
			*(Object::Vector2D*)&params[0] = out_ViewportSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewportSize = *(Object::Vector2D*)&params[0];
		}
		bool IsFullScreenViewport()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.IsFullScreenViewport");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ShouldForceFullscreenViewport()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.ShouldForceFullscreenViewport");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetNumCustomInteractions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetNumCustomInteractions");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		ScriptClass* GetCustomInteractionClass(int InIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetCustomInteractionClass");
			byte params[8] = { NULL };
			*(int*)&params[0] = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		void SetCustomInteractionObject(class Interaction* InInteraction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.SetCustomInteractionObject");
			byte params[4] = { NULL };
			*(class Interaction**)&params[0] = InInteraction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class LocalPlayer* CreatePlayer(int ControllerId, ScriptString*& OutError, bool bSpawnActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CreatePlayer");
			byte params[24] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptString**)&params[4] = OutError;
			*(bool*)&params[16] = bSpawnActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)&params[4];
			return *(class LocalPlayer**)&params[20];
		}
		int AddLocalPlayer(class LocalPlayer* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.AddLocalPlayer");
			byte params[8] = { NULL };
			*(class LocalPlayer**)&params[0] = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int RemoveLocalPlayer(class LocalPlayer* ExistingPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.RemoveLocalPlayer");
			byte params[8] = { NULL };
			*(class LocalPlayer**)&params[0] = ExistingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.NotifyPlayerAdded");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			*(class LocalPlayer**)&params[4] = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RemovePlayer(class LocalPlayer* ExPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.RemovePlayer");
			byte params[8] = { NULL };
			*(class LocalPlayer**)&params[0] = ExPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.NotifyPlayerRemoved");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			*(class LocalPlayer**)&params[4] = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class LocalPlayer* FindPlayerByControllerId(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.FindPlayerByControllerId");
			byte params[8] = { NULL };
			*(int*)&params[0] = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class LocalPlayer**)&params[4];
		}
		bool CreateViewportConsole(ScriptClass* vpcClass, ScriptString*& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CreateViewportConsole");
			byte params[20] = { NULL };
			*(ScriptClass**)&params[0] = vpcClass;
			*(ScriptString**)&params[4] = OutError;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		bool Init(ScriptString*& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.Init");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = OutError;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)&params[0];
			return *(bool*)&params[12];
		}
		bool CreateInitialPlayer(ScriptString*& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CreateInitialPlayer");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = OutError;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)&params[0];
			return *(bool*)&params[12];
		}
		int InsertInteraction(class Interaction* NewInteraction, int InIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.InsertInteraction");
			byte params[12] = { NULL };
			*(class Interaction**)&params[0] = NewInteraction;
			*(int*)&params[4] = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void GameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSplitscreenConfiguration(GameViewportClient::ESplitScreenType SplitType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.SetSplitscreenConfiguration");
			byte params[1] = { NULL };
			*(GameViewportClient::ESplitScreenType*)&params[0] = SplitType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GameViewportClient::ESplitScreenType GetSplitscreenConfiguration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetSplitscreenConfiguration");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GameViewportClient::ESplitScreenType*)&params[0];
		}
		void UpdateActiveSplitscreenType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.UpdateActiveSplitscreenType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LayoutPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.LayoutPlayers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetSubtitleRegion(Object::Vector2D& MinPos, Object::Vector2D& MaxPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetSubtitleRegion");
			byte params[16] = { NULL };
			*(Object::Vector2D*)&params[0] = MinPos;
			*(Object::Vector2D*)&params[8] = MaxPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MinPos = *(Object::Vector2D*)&params[0];
			MaxPos = *(Object::Vector2D*)&params[8];
		}
		int ConvertLocalPlayerToGamePlayerIndex(class LocalPlayer* LPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.ConvertLocalPlayerToGamePlayerIndex");
			byte params[8] = { NULL };
			*(class LocalPlayer**)&params[0] = LPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool HasTopSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HasTopSafeZone");
			byte params[8] = { NULL };
			*(int*)&params[0] = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasBottomSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HasBottomSafeZone");
			byte params[8] = { NULL };
			*(int*)&params[0] = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasLeftSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HasLeftSafeZone");
			byte params[8] = { NULL };
			*(int*)&params[0] = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasRightSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HasRightSafeZone");
			byte params[8] = { NULL };
			*(int*)&params[0] = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetPixelSizeOfScreen(float& out_Width, float& out_Height, class Canvas* Canvas, int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetPixelSizeOfScreen");
			byte params[16] = { NULL };
			*(float*)&params[0] = out_Width;
			*(float*)&params[4] = out_Height;
			*(class Canvas**)&params[8] = Canvas;
			*(int*)&params[12] = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Width = *(float*)&params[0];
			out_Height = *(float*)&params[4];
		}
		void CalculateSafeZoneValues(float& out_Horizontal, float& out_Vertical, class Canvas* Canvas, int LocalPlayerIndex, bool bUseMaxPercent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CalculateSafeZoneValues");
			byte params[20] = { NULL };
			*(float*)&params[0] = out_Horizontal;
			*(float*)&params[4] = out_Vertical;
			*(class Canvas**)&params[8] = Canvas;
			*(int*)&params[12] = LocalPlayerIndex;
			*(bool*)&params[16] = bUseMaxPercent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Horizontal = *(float*)&params[0];
			out_Vertical = *(float*)&params[4];
		}
		bool CalculateDeadZoneForAllSides(class LocalPlayer* LPlayer, class Canvas* Canvas, float& fTopSafeZone, float& fBottomSafeZone, float& fLeftSafeZone, float& fRightSafeZone, bool bUseMaxPercent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CalculateDeadZoneForAllSides");
			byte params[32] = { NULL };
			*(class LocalPlayer**)&params[0] = LPlayer;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTitleSafeArea(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DrawTitleSafeArea");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.PostRender");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayProgressMessage(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DisplayProgressMessage");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTransition(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DrawTransition");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTransitionMessage(class Canvas* Canvas, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DrawTransitionMessage");
			byte params[16] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetProgressMessage(PlayerController::EProgressMessageType MessageType, ScriptString* Message, ScriptString* Title, bool bIgnoreFutureNetworkMessages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.SetProgressMessage");
			byte params[29] = { NULL };
			*(PlayerController::EProgressMessageType*)&params[0] = MessageType;
			*(ScriptString**)&params[4] = Message;
			*(ScriptString**)&params[16] = Title;
			*(bool*)&params[28] = bIgnoreFutureNetworkMessages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyConnectionError(ScriptString* Message, ScriptString* Title)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.NotifyConnectionError");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(ScriptString**)&params[12] = Title;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetProgressTime(float T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.SetProgressTime");
			byte params[4] = { NULL };
			*(float*)&params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearProgressMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.ClearProgressMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class LocalPlayer* GetPlayerOwner(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetPlayerOwner");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class LocalPlayer**)&params[4];
		}
		void FixupOwnerReferences()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.FixupOwnerReferences");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPrimaryPlayerSwitch(class LocalPlayer* OldPrimaryPlayer, class LocalPlayer* NewPrimaryPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.OnPrimaryPlayerSwitch");
			byte params[8] = { NULL };
			*(class LocalPlayer**)&params[0] = OldPrimaryPlayer;
			*(class LocalPlayer**)&params[4] = NewPrimaryPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BecomePrimaryPlayer(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.BecomePrimaryPlayer");
			byte params[4] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DebugSetUISystemEnabled(bool bOldUISystemActive, bool bGFxUISystemActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DebugSetUISystemEnabled");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bOldUISystemActive;
			*(bool*)&params[4] = bGFxUISystemActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
