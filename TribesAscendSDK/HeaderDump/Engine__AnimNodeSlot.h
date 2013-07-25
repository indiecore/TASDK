#pragma once
#include "Engine__AnimNodeBlendBase.h"
#include "Engine__AnimNodeSynch.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNodeSlot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeSlot : public AnimNodeBlendBase
	{
	public:
		ADD_OBJECT(AnimNodeSynch, SynchNode)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TargetChildIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CustomChildIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PendingBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAdditiveAnimationsOverrideSource, 0x8)
		ADD_VAR(::BoolProperty, bSkipBlendWhenNotRendered, 0x4)
		ADD_VAR(::BoolProperty, bEarlyAnimEndNotify, 0x2)
		ADD_VAR(::BoolProperty, bIsPlayingCustomAnim, 0x1)
		// Here lies the not-yet-implemented method 'PlayCustomAnim'
		// Here lies the not-yet-implemented method 'PlayCustomAnimByDuration'
		// Here lies the not-yet-implemented method 'GetPlayedAnimation'
		// Here lies the not-yet-implemented method 'StopCustomAnim'
		// Here lies the not-yet-implemented method 'SetCustomAnim'
		// Here lies the not-yet-implemented method 'SetActorAnimEndNotification'
		// Here lies the not-yet-implemented method 'GetCustomAnimNodeSeq'
		// Here lies the not-yet-implemented method 'SetRootBoneAxisOption'
		// Here lies the not-yet-implemented method 'SetRootBoneRotationOption'
		// Here lies the not-yet-implemented method 'AddToSynchGroup'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
