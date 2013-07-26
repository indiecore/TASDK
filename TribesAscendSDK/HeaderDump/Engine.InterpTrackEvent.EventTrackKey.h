#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrackEvent.EventTrackKey." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EventTrackKey
	{
	public:
		ADD_VAR(::NameProperty, EventName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
