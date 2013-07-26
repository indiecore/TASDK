#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AmbientSoundSimpleToggleable.CheckpointRecord." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CheckpointRecord
	{
	public:
		ADD_VAR(::BoolProperty, bCurrentlyPlaying, 0x1)
	};
}
#undef ADD_VAR
