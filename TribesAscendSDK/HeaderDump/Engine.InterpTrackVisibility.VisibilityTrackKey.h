#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrackVisibility.VisibilityTrackKey." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VisibilityTrackKey
	{
	public:
		ADD_VAR(::ByteProperty, ActiveCondition, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Action, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
