#pragma once
#include "Engine__AnimNodeBlend.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeCrossfader." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeCrossfader : public AnimNodeBlend
	{
	public:
		ADD_VAR(::FloatProperty, PendingBlendOutTimeOneShot, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDontBlendOutOneShot, 0x1)
		ADD_VAR(::NameProperty, DefaultAnimSeqName, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PlayOneShotAnim'
		// Here lies the not-yet-implemented method 'BlendToLoopingAnim'
		// Here lies the not-yet-implemented method 'GetAnimName'
		// Here lies the not-yet-implemented method 'GetActiveChild'
	};
}
#undef ADD_VAR
