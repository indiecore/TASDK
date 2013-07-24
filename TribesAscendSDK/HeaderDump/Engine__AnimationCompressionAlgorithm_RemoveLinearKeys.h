#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimationCompressionAlgorithm_RemoveLinearKeys." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimationCompressionAlgorithm_RemoveLinearKeys : public AnimationCompressionAlgorithm
	{
	public:
		ADD_VAR(::BoolProperty, bActuallyFilterLinearKeys, 0x2)
		ADD_VAR(::BoolProperty, bRetarget, 0x1)
		ADD_VAR(::FloatProperty, ParentKeyScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EffectorDiffSocket, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinEffectorDiff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxEffectorDiff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxAngleDiff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPosDiff, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
