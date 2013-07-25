#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_CameraShake." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_CameraShake." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_CameraShake : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bRadialShake, 0x2)
		ADD_OBJECT(Actor, LocationActor)
		ADD_OBJECT(CameraShake, Shake)
		ADD_VAR(::FloatProperty, RadialShake_InnerRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialShake_OuterRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialShake_Falloff, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDoControllerVibration, 0x1)
		ADD_VAR(::BoolProperty, bOrientTowardRadialEpicenter, 0x4)
		ADD_VAR(::FloatProperty, ShakeScale, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PlaySpace, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
