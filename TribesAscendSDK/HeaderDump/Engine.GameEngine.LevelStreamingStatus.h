#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameEngine.LevelStreamingStatus." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LevelStreamingStatus
	{
	public:
		ADD_VAR(::NameProperty, PackageName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShouldBeLoaded, 0x1)
		ADD_VAR(::BoolProperty, bShouldBeVisible, 0x2)
	};
}
#undef ADD_VAR
