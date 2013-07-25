#pragma once
#include "Engine__AnimNotify.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNotify_Rumble." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNotify_Rumble." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotify_Rumble : public AnimNotify
	{
	public:
		ADD_OBJECT(ForceFeedbackWaveform, WaveForm)
		ADD_VAR(::FloatProperty, EffectRadius, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCheckForBasedPlayer, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
