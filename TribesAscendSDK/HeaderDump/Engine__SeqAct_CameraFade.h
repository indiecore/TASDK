#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_CameraFade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_CameraFade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_CameraFade : public SequenceAction
	{
	public:
		ADD_VAR(::FloatProperty, FadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPersistFade, 0x1)
		ADD_VAR(::FloatProperty, FadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOpacity, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'FadeAlpha'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'FadeColor'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
