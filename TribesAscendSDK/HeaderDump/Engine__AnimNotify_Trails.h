#pragma once
#include "Engine__AnimNotify.h"
#include "Engine__AnimNodeSequence.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNotify_Trails." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNotify_Trails." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNotify_Trails : public AnimNotify
	{
	public:
		ADD_OBJECT(AnimNodeSequence, AnimNodeSeq)
		ADD_VAR(::FloatProperty, TimeStep, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SamplesPerSecond, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SampleTimeStep, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastStartTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SecondEdgeSocketName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ControlPointSocketName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FirstEdgeSocketName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bResampleRequired, 0x8)
		ADD_VAR(::BoolProperty, bSkipIfOwnerIsHidden, 0x4)
		ADD_VAR(::BoolProperty, bPreview, 0x2)
		ADD_VAR(::BoolProperty, bIsExtremeContent, 0x1)
		ADD_OBJECT(ParticleSystem, PSTemplate)
		// Here lies the not-yet-implemented method 'GetNumSteps'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
