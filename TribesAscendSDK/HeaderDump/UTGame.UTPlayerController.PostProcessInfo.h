#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTPlayerController.PostProcessInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PostProcessInfo
	{
	public:
		ADD_VAR(::FloatProperty, Desaturation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighLights, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidTones, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Shadows, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
