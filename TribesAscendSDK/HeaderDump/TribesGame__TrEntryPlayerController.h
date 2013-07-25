#pragma once
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__TrPaperDollMainMenu.h"
#include "TribesGame__TrMainMenuContentData.h"
#include "Engine__LocalPlayer.h"
#include "Engine__PostProcessChain.h"
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
		ADD_STRUCT(::RotatorProperty, m_rTargetCameraRotation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, m_rInitialCameraRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_CameraLocation4x3, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_CameraLocation16x10, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_CameraLocation16x9, 0xFFFFFFFF
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
		// Here lies the not-yet-implemented method 'RequestPaperDoll'
		// Here lies the not-yet-implemented method 'SendMenuToLobby'
		// Here lies the not-yet-implemented method 'ResendReadyCheck'
		// Here lies the not-yet-implemented method 'UpdateMenuTimer'
		// Here lies the not-yet-implemented method 'GetWaitRemaining'
		// Here lies the not-yet-implemented method 'NotifyMenuReady'
		// Here lies the not-yet-implemented method 'RefreshFriends'
		// Here lies the not-yet-implemented method 'SwapModel'
		// Here lies the not-yet-implemented method 'ShowPeach'
		// Here lies the not-yet-implemented method 'ToggleMenuVisible'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'GetPlayerViewPoint'
		// Here lies the not-yet-implemented method 'SwingCamera'
		// Here lies the not-yet-implemented method 'SwingCameraBack'
		// Here lies the not-yet-implemented method 'PreloadTexturesTimer'
		// Here lies the not-yet-implemented method 'NotifyMenuReadyTimer'
		// Here lies the not-yet-implemented method 'RequestPaperDollTimer'
		// Here lies the not-yet-implemented method 'BeginQueueResendTimer'
		// Here lies the not-yet-implemented method 'ClearQueueResendTimer'
		// Here lies the not-yet-implemented method 'LoadingTimer'
		// Here lies the not-yet-implemented method 'InitInputSystem'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'OnControllerChanged'
		// Here lies the not-yet-implemented method 'OnGameInviteReceived'
		// Here lies the not-yet-implemented method 'OnFriendInviteReceived'
		// Here lies the not-yet-implemented method 'OnFriendMessageReceived'
		// Here lies the not-yet-implemented method 'OnConnectionStatusChange'
		// Here lies the not-yet-implemented method 'OnLinkStatusChanged'
		// Here lies the not-yet-implemented method 'QuitToMainMenu'
		// Here lies the not-yet-implemented method 'SetPawnConstructionScene'
		// Here lies the not-yet-implemented method 'ShowMidGameMenu'
		// Here lies the not-yet-implemented method 'ShowScoreboard'
		// Here lies the not-yet-implemented method 'Pose'
		// Here lies the not-yet-implemented method 'Weap'
		// Here lies the not-yet-implemented method 'Char'
		// Here lies the not-yet-implemented method 'UpdatePaperDoll_Device'
		// Here lies the not-yet-implemented method 'ClearMainMenuPaperDoll'
		// Here lies the not-yet-implemented method 'UpdateMainMenuPaperDoll_Mesh'
		// Here lies the not-yet-implemented method 'UpdatePaperDoll'
		// Here lies the not-yet-implemented method 'OnDeviceContentDataClassLoaded'
		// Here lies the not-yet-implemented method 'OnClassSelectedMainMenu'
		// Here lies the not-yet-implemented method 'On3PSkinContentLoaded'
		// Here lies the not-yet-implemented method 'RefreshFriendsTimer'
		// Here lies the not-yet-implemented method 'SwapModelTimer'
		// Here lies the not-yet-implemented method 'ShowPeachTimer'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
