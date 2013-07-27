#pragma once
#include "TribesGame.TrPlayerController.h"
#include "Core.Object.h"
#include "Engine.PostProcessChain.h"
#include "TribesGame.TrObject.h"
#include "Engine.LocalPlayer.h"
#include "TribesGame.TrPaperDollMainMenu.h"
#include "Engine.OnlineSubsystem.h"
#include "TribesGame.TrMainMenuContentData.h"
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
	class TrEntryPlayerController : public TrPlayerController
	{
	public:
		ADD_BOOL(bMenuNotified, 3444, 0x1)
		ADD_STRUCT(ScriptArray<class PostProcessChain*>, OldPostProcessChain, 3452)
		ADD_STRUCT(float, m_fCameraRotationInterpTime, 3560)
		ADD_STRUCT(float, m_fCameraRotationCurrTime, 3556)
		ADD_STRUCT(Object::Rotator, m_rTargetCameraRotation, 3544)
		ADD_STRUCT(Object::Rotator, m_rInitialCameraRotation, 3532)
		ADD_STRUCT(Object::Vector, m_CameraLocation4x3, 3520)
		ADD_STRUCT(Object::Vector, m_CameraLocation16x10, 3508)
		ADD_STRUCT(Object::Vector, m_CameraLocation16x9, 3496)
		ADD_STRUCT(float, m_PreloadTextureTime, 3492)
		ADD_STRUCT(TrObject::EContentDataType, m_ContentDataType, 3488)
		ADD_OBJECT(TrPaperDollMainMenu, m_MainMenuPaperDoll, 3484)
		ADD_STRUCT(ScriptString*, MainMenuContentClassName, 3472)
		ADD_OBJECT(TrMainMenuContentData, m_MainMenuContentData, 3468)
		ADD_OBJECT(LocalPlayer, OldPlayer, 3464)
		ADD_OBJECT(PostProcessChain, EntryPostProcessChain, 3448)
		ADD_STRUCT(int, MAX_RESEND_WAIT_TIME, 3440)
		ADD_STRUCT(int, MIN_RESEND_WAIT_TIME, 3436)
		ADD_STRUCT(int, m_CountdownTime, 3432)
		bool RequestPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.RequestPaperDoll");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SendMenuToLobby()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.SendMenuToLobby");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResendReadyCheck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ResendReadyCheck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMenuTimer(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.UpdateMenuTimer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetWaitRemaining()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.GetWaitRemaining");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void NotifyMenuReady()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.NotifyMenuReady");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshFriends()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.RefreshFriends");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwapModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.SwapModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowPeach()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ShowPeach");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleMenuVisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ToggleMenuVisible");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Object::Vector& POVLocation, Object::Rotator& POVRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.GetPlayerViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = POVLocation;
			*(Object::Rotator*)&params[12] = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			POVLocation = *(Object::Vector*)&params[0];
			POVRotation = *(Object::Rotator*)&params[12];
		}
		void SwingCamera(float TargetPitch, float TargetYaw, float TargetRoll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.SwingCamera");
			byte params[12] = { NULL };
			*(float*)&params[0] = TargetPitch;
			*(float*)&params[4] = TargetYaw;
			*(float*)&params[8] = TargetRoll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwingCameraBack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.SwingCameraBack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreloadTexturesTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.PreloadTexturesTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyMenuReadyTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.NotifyMenuReadyTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestPaperDollTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.RequestPaperDollTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginQueueResendTimer(int SecondsLeft)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.BeginQueueResendTimer");
			byte params[4] = { NULL };
			*(int*)&params[0] = SecondsLeft;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQueueResendTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ClearQueueResendTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadingTimer(bool bStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.LoadingTimer");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.InitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnControllerChanged");
			byte params[8] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(bool*)&params[4] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptString* RequestingNick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnGameInviteReceived");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = RequestingNick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnFriendInviteReceived");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnFriendMessageReceived");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnConnectionStatusChange(OnlineSubsystem::EOnlineServerConnectionStatus ConnectionStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnConnectionStatusChange");
			byte params[1] = { NULL };
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)&params[0] = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLinkStatusChanged(bool bConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnLinkStatusChanged");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QuitToMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.QuitToMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPawnConstructionScene(bool bShow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.SetPawnConstructionScene");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowMidGameMenu(ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ShowMidGameMenu");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = TabTag;
			*(bool*)&params[8] = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowScoreboard()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ShowScoreboard");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pose(int PoseId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.Pose");
			byte params[4] = { NULL };
			*(int*)&params[0] = PoseId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Weap(int WeapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.Weap");
			byte params[4] = { NULL };
			*(int*)&params[0] = WeapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Char(int CharID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.Char");
			byte params[4] = { NULL };
			*(int*)&params[0] = CharID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePaperDoll_Device(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.UpdatePaperDoll_Device");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMainMenuPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ClearMainMenuPaperDoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMainMenuPaperDoll_Mesh(TrObject::EContentDataType Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.UpdateMainMenuPaperDoll_Mesh");
			byte params[1] = { NULL };
			*(TrObject::EContentDataType*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePaperDoll(ScriptClass* FamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.UpdatePaperDoll");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfoClass;
			*(ScriptClass**)&params[4] = DeviceClass;
			*(ScriptClass**)&params[8] = skinClass;
			*(int*)&params[12] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnDeviceContentDataClassLoaded");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClassSelectedMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnClassSelectedMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void On3PSkinContentLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.On3PSkinContentLoaded");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshFriendsTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.RefreshFriendsTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwapModelTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.SwapModelTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowPeachTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ShowPeachTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
