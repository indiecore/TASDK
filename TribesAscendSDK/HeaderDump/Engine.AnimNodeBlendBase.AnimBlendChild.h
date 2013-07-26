#pragma once
#include "Engine.AnimNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNodeBlendBase.AnimBlendChild." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AnimNodeBlendBase.AnimBlendChild." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimBlendChild
	{
	public:
		ADD_OBJECT(AnimNode, Anim)
		ADD_VAR(::IntProperty, DrawY, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsAdditive, 0x2)
		ADD_VAR(::BoolProperty, bMirrorSkeleton, 0x1)
		ADD_VAR(::FloatProperty, BlendWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Weight, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Name, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
