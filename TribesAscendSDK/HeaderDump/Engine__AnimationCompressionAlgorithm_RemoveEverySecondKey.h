#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimationCompressionAlgorithm_RemoveEverySecondKey." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimationCompressionAlgorithm_RemoveEverySecondKey : public AnimationCompressionAlgorithm
	{
	public:
		ADD_VAR(::BoolProperty, bStartAtSecondKey, 0x1)
		ADD_VAR(::IntProperty, MinKeys, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
