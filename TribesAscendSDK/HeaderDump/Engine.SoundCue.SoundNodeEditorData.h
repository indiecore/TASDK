#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SoundCue.SoundNodeEditorData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeEditorData
	{
	public:
		ADD_VAR(::IntProperty, NodePosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NodePosX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
