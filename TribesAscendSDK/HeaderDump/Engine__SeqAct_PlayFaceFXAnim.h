#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_PlayFaceFXAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_PlayFaceFXAnim." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_PlayFaceFXAnim : public SequenceAction
	{
	public:
		ADD_OBJECT(FaceFXAnimSet, FaceFXAnimSetRef)
		ADD_VAR(::StrProperty, FaceFXAnimName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FaceFXGroupName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, SoundCueToPlay)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
