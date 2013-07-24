#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNodeSlot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeSlot : public AnimNodeBlendBase
	{
	public:
		ADD_OBJECT(AnimNodeSynch, SynchNode)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TargetChildIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CustomChildIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PendingBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAdditiveAnimationsOverrideSource, 0x8)
		ADD_VAR(::BoolProperty, bSkipBlendWhenNotRendered, 0x4)
		ADD_VAR(::BoolProperty, bEarlyAnimEndNotify, 0x2)
		ADD_VAR(::BoolProperty, bIsPlayingCustomAnim, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
