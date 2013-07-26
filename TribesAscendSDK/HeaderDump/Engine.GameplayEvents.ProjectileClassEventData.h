#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameplayEvents.ProjectileClassEventData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ProjectileClassEventData
	{
	public:
		ADD_VAR(::StrProperty, ProjectileClassName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
