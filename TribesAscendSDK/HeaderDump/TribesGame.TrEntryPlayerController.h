#pragma once
#include "TribesGame.TrPlayerController.h"
#include "Engine.LocalPlayer.h"
#include "TribesGame.TrPaperDollMainMenu.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
#include "TribesGame.TrMainMenuContentData.h"
#include "Engine.PostProcessChain.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEntryPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrEntryPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrEntryPlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrEntryPlayerController : public TrPlayerController
	{
	public:
		ADD_VAR(::BoolProperty, bMenuNotified, 0x1)
		ADD_VAR(::FloatProperty, m_fCameraRotationInterpTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCameraRotationCurrTime, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rTargetCameraRotation, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rInitialCameraRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_CameraLocation4x3, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_CameraLocation16x10, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_CameraLocation16x9, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_PreloadTextureTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_ContentDataType, 0xFFFFFFFF)
		ADD_OBJECT(TrPaperDollMainMenu, m_MainMenuPaperDoll)
		ADD_VAR(::StrProperty, MainMenuContentClassName, 0xFFFFFFFF)
		ADD_OBJECT(TrMainMenuContentData, m_MainMenuContentData)
		ADD_OBJECT(LocalPlayer, OldPlayer)
		ADD_OBJECT(PostProcessChain, EntryPostProcessChain)
		ADD_VAR(::IntProperty, MAX_RESEND_WAIT_TIME, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MIN_RESEND_WAIT_TIME, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_CountdownTime, 0xFFFFFFFF)
		bool RequestPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.RequestPaperDoll");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetWaitRemaining()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.GetWaitRemaining");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
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
		void GetPlayerViewPoint(Vector& POVLocation, Rotator& POVRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.GetPlayerViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = POVLocation;
			*(Rotator*)(params + 12) = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			POVLocation = *(Vector*)params;
			POVRotation = *(Rotator*)(params + 12);
			free(params);
		}
		void SwingCamera(float TargetPitch, float TargetYaw, float TargetRoll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.SwingCamera");
			byte* params = (byte*)malloc(12);
			*(float*)params = TargetPitch;
			*(float*)(params + 4) = TargetYaw;
			*(float*)(params + 8) = TargetRoll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = SecondsLeft;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearQueueResendTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ClearQueueResendTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadingTimer(bool bStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.LoadingTimer");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bStart;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			*(bool*)(params + 4) = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptArray<wchar_t> RequestingNick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnGameInviteReceived");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = RequestingNick;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendInviteReceived(byte LocalUserNum, UniqueNetId RequestingPlayer, ScriptArray<wchar_t> RequestingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnFriendInviteReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = RequestingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = RequestingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendMessageReceived(byte LocalUserNum, UniqueNetId SendingPlayer, ScriptArray<wchar_t> SendingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnFriendMessageReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = SendingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = SendingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnConnectionStatusChange(byte ConnectionStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnConnectionStatusChange");
			byte* params = (byte*)malloc(1);
			*params = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLinkStatusChanged(bool bConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnLinkStatusChanged");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void QuitToMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.QuitToMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPawnConstructionScene(bool bShow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.SetPawnConstructionScene");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowMidGameMenu(ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ShowMidGameMenu");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = TabTag;
			*(bool*)(params + 8) = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowScoreboard()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ShowScoreboard");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pose(int PoseId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.Pose");
			byte* params = (byte*)malloc(4);
			*(int*)params = PoseId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Weap(int WeapId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.Weap");
			byte* params = (byte*)malloc(4);
			*(int*)params = WeapId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Char(int CharID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.Char");
			byte* params = (byte*)malloc(4);
			*(int*)params = CharID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdatePaperDoll_Device(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.UpdatePaperDoll_Device");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearMainMenuPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.ClearMainMenuPaperDoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMainMenuPaperDoll_Mesh(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.UpdateMainMenuPaperDoll_Mesh");
			byte* params = (byte*)malloc(1);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdatePaperDoll(ScriptClass* FamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.UpdatePaperDoll");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = FamilyInfoClass;
			*(ScriptClass**)(params + 4) = DeviceClass;
			*(ScriptClass**)(params + 8) = skinClass;
			*(int*)(params + 12) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnDeviceContentDataClassLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnClassSelectedMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.OnClassSelectedMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void On3PSkinContentLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEntryPlayerController.On3PSkinContentLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
