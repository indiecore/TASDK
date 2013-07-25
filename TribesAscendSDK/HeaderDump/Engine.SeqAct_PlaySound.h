#pragma once
#include "Engine.SeqAct_Latent.h"
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_PlaySound." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_PlaySound." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_PlaySound : public SeqAct_Latent
	{
	public:
		ADD_VAR(::BoolProperty, bStopped, 0x2)
		ADD_VAR(::BoolProperty, bSuppressSubtitles, 0x1)
		ADD_VAR(::FloatProperty, PitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VolumeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoundDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExtraDelay, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PlaySound)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_PlaySound.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
