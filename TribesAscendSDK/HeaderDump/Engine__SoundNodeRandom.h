#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeRandom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeRandom : public SoundNode
	{
	public:
		ADD_VAR(::IntProperty, NumRandomUsed, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRandomizeWithoutReplacement, 0x1)
	};
}
#undef ADD_VAR
