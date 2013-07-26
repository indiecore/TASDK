#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrackAnimControl.AnimControlTrackKey." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimControlTrackKey
	{
	public:
		ADD_VAR(::BoolProperty, bReverse, 0x2)
		ADD_VAR(::BoolProperty, bLooping, 0x1)
		ADD_VAR(::FloatProperty, AnimPlayRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimEndOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimStartOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimSeqName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
