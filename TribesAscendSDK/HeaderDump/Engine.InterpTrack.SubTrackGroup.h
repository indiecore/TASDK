#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrack.SubTrackGroup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SubTrackGroup
	{
	public:
		ADD_VAR(::BoolProperty, bIsSelected, 0x2)
		ADD_VAR(::BoolProperty, bIsCollapsed, 0x1)
		ADD_VAR(::StrProperty, GroupName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
