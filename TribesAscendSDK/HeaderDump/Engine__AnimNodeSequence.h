#pragma once
#include "Engine__AnimNode.h"
#include "Engine__AnimSequence.h"
#include "Engine__CameraAnim.h"
#include "Engine__CameraAnimInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeSequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNodeSequence." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeSequence : public AnimNode
	{
	public:
		ADD_OBJECT(AnimSequence, AnimSeq)
		ADD_VAR(::BoolProperty, bPlaying, 0x1)
		ADD_VAR(::FloatProperty, Rate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLooping, 0x2)
		ADD_VAR(::NameProperty, AnimSeqName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCauseActorAnimEnd, 0x4)
		ADD_VAR(::BoolProperty, bCauseActorAnimPlay, 0x8)
		ADD_VAR(::BoolProperty, bZeroRootRotation, 0x10)
		ADD_VAR(::BoolProperty, bZeroRootTranslation, 0x20)
		ADD_VAR(::BoolProperty, bDisableWarningWhenAnimNotFound, 0x40)
		ADD_VAR(::BoolProperty, bNoNotifies, 0x80)
		ADD_VAR(::BoolProperty, bForceRefposeWhenNotPlaying, 0x100)
		ADD_VAR(::BoolProperty, bIsIssuingNotifies, 0x200)
		ADD_VAR(::BoolProperty, m_bSuppressNotifies, 0x400)
		ADD_VAR(::BoolProperty, bForceAlwaysSlave, 0x800)
		ADD_VAR(::BoolProperty, bSynchronize, 0x1000)
		ADD_VAR(::BoolProperty, bReverseSync, 0x2000)
		ADD_VAR(::BoolProperty, bShowTimeLineSlider, 0x4000)
		ADD_VAR(::BoolProperty, bLoopCameraAnim, 0x8000)
		ADD_VAR(::BoolProperty, bRandomizeCameraAnimLoopStartTime, 0x10000)
		ADD_VAR(::BoolProperty, bEditorOnlyAddRefPoseToAdditiveAnimation, 0x20000)
		ADD_VAR(::FloatProperty, CurrentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PreviousTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AnimLinkupIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NotifyWeightThreshold, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SynchGroupName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SynchPosOffset, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnim, CameraAnim)
		ADD_OBJECT(CameraAnimInst, ActiveCameraAnimInstance)
		ADD_VAR(::FloatProperty, CameraAnimScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraAnimPlayRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraAnimBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraAnimBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RootBoneOption, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RootRotationOption, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetAnim'
		// Here lies the not-yet-implemented method 'PlayAnim'
		// Here lies the not-yet-implemented method 'StopAnim'
		// Here lies the not-yet-implemented method 'ReplayAnim'
		// Here lies the not-yet-implemented method 'SetPosition'
		// Here lies the not-yet-implemented method 'GetNormalizedPosition'
		// Here lies the not-yet-implemented method 'FindGroupRelativePosition'
		// Here lies the not-yet-implemented method 'FindGroupPosition'
		// Here lies the not-yet-implemented method 'GetGroupRelativePosition'
		// Here lies the not-yet-implemented method 'GetGlobalPlayRate'
		// Here lies the not-yet-implemented method 'GetAnimPlaybackLength'
		// Here lies the not-yet-implemented method 'GetTimeLeft'
		// Here lies the not-yet-implemented method 'SetRootBoneAxisOption'
		// Here lies the not-yet-implemented method 'SetRootBoneRotationOption'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
