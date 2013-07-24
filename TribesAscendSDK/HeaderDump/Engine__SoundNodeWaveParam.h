#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeWaveParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeWaveParam : public SoundNode
	{
	public:
		ADD_VAR(::NameProperty, WaveParameterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
