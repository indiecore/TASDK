#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimationCompressionAlgorithm_RemoveTrivialKeys." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimationCompressionAlgorithm_RemoveTrivialKeys : public AnimationCompressionAlgorithm
	{
	public:
		ADD_VAR(::FloatProperty, MaxAngleDiff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPosDiff, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
