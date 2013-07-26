#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " LandscapeComponent.LandscapeComponentAlphaInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LandscapeComponentAlphaInfo
	{
	public:
		ADD_VAR(::IntProperty, LayerIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
