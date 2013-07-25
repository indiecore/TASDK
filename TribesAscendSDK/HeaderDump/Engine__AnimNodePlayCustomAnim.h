#pragma once
#include "Engine__AnimNodeBlend.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodePlayCustomAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodePlayCustomAnim : public AnimNodeBlend
	{
	public:
		ADD_VAR(::FloatProperty, CustomPendingBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsPlayingCustomAnim, 0x1)
		// Here lies the not-yet-implemented method 'PlayCustomAnim'
		// Here lies the not-yet-implemented method 'PlayCustomAnimByDuration'
		// Here lies the not-yet-implemented method 'StopCustomAnim'
		// Here lies the not-yet-implemented method 'SetCustomAnim'
		// Here lies the not-yet-implemented method 'SetActorAnimEndNotification'
		// Here lies the not-yet-implemented method 'GetCustomAnimNodeSeq'
		// Here lies the not-yet-implemented method 'SetRootBoneAxisOption'
	};
}
#undef ADD_VAR
