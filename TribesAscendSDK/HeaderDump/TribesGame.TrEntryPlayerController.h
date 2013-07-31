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
		ADD_STRUCT(Rotator, m_rTargetCameraRotation, 3544)
		ADD_STRUCT(Rotator, m_rInitialCameraRotation, 3532)
		ADD_STRUCT(Vector, m_CameraLocation4x3, 3520)
		ADD_STRUCT(Vector, m_CameraLocation16x10, 3508)
		ADD_STRUCT(Vector, m_CameraLocation16x9, 3496)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87308);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SendMenuToLobby()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87310);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResendReadyCheck()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87311);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMenuTimer(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87312);
			byte params[4] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetWaitRemaining()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87314);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void NotifyMenuReady()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87316);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshFriends()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87317);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwapModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87318);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowPeach()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87319);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleMenuVisible()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87320);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87321);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& POVLocation, Rotator& POVRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87325);
			byte params[24] = { NULL };
			*(Vector*)params = POVLocation;
			*(Rotator*)&params[12] = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			POVLocation = *(Vector*)params;
			POVRotation = *(Rotator*)&params[12];
		}
		void SwingCamera(float TargetPitch, float TargetYaw, float TargetRoll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87332);
			byte params[12] = { NULL };
			*(float*)params = TargetPitch;
			*(float*)&params[4] = TargetYaw;
			*(float*)&params[8] = TargetRoll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwingCameraBack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87337);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreloadTexturesTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87339);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyMenuReadyTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87340);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestPaperDollTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87341);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginQueueResendTimer(int SecondsLeft)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87342);
			byte params[4] = { NULL };
			*(int*)params = SecondsLeft;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQueueResendTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87344);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadingTimer(bool bStart)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87345);
			byte params[4] = { NULL };
			*(bool*)params = bStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87347);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87348);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87349);
			byte params[8] = { NULL };
			*(int*)params = ControllerId;
			*(bool*)&params[4] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptString* RequestingNick)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87353);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = RequestingNick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87356);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87361);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnConnectionStatusChange(OnlineSubsystem::EOnlineServerConnectionStatus ConnectionStatus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87366);
			byte params[1] = { NULL };
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)params = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLinkStatusChanged(bool bConnected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87369);
			byte params[4] = { NULL };
			*(bool*)params = bConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QuitToMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87372);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPawnConstructionScene(bool bShow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87373);
			byte params[4] = { NULL };
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowMidGameMenu(ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87375);
			byte params[12] = { NULL };
			*(ScriptName*)params = TabTag;
			*(bool*)&params[8] = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowScoreboard()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87378);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Pose(int PoseId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87379);
			byte params[4] = { NULL };
			*(int*)params = PoseId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Weap(int WeapId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87381);
			byte params[4] = { NULL };
			*(int*)params = WeapId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Char(int CharID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87383);
			byte params[4] = { NULL };
			*(int*)params = CharID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePaperDoll_Device(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87392);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMainMenuPaperDoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87394);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMainMenuPaperDoll_Mesh(TrObject::EContentDataType Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87395);
			byte params[1] = { NULL };
			*(TrObject::EContentDataType*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePaperDoll(ScriptClass* FamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87398);
			byte params[16] = { NULL };
			*(ScriptClass**)params = FamilyInfoClass;
			*(ScriptClass**)&params[4] = DeviceClass;
			*(ScriptClass**)&params[8] = skinClass;
			*(int*)&params[12] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87403);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClassSelectedMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87405);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void On3PSkinContentLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87406);
			byte params[4] = { NULL };
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshFriendsTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87408);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwapModelTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87409);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowPeachTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87410);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
