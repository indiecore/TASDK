#pragma once
#include "TribesGame__TrPlayerController.h"
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
