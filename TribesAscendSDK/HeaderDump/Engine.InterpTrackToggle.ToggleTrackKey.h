#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrackToggle.ToggleTrackKey." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ToggleTrackKey
	{
	public:
		ADD_VAR(::ByteProperty, ToggleAction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
