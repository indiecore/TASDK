#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrackMove.InterpLookupPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpLookupPoint
	{
	public:
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, GroupName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
