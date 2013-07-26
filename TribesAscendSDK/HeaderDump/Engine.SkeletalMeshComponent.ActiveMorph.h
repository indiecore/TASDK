#pragma once
#include "Engine.MorphTarget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMeshComponent.ActiveMorph." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SkeletalMeshComponent.ActiveMorph." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActiveMorph
	{
	public:
		ADD_OBJECT(MorphTarget, Target)
		ADD_VAR(::FloatProperty, Weight, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
