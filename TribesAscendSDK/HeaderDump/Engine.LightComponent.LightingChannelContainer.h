#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " LightComponent.LightingChannelContainer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LightingChannelContainer
	{
	public:
		ADD_VAR(::BoolProperty, Crowd, 0x4000000)
		ADD_VAR(::BoolProperty, Gameplay, 0x2000000)
		ADD_VAR(::BoolProperty, Gameplay, 0x1000000)
		ADD_VAR(::BoolProperty, Gameplay, 0x800000)
		ADD_VAR(::BoolProperty, Gameplay, 0x400000)
		ADD_VAR(::BoolProperty, Cinematic, 0x200000)
		ADD_VAR(::BoolProperty, Cinematic, 0x100000)
		ADD_VAR(::BoolProperty, Cinematic, 0x80000)
		ADD_VAR(::BoolProperty, Cinematic, 0x40000)
		ADD_VAR(::BoolProperty, Cinematic, 0x20000)
		ADD_VAR(::BoolProperty, Cinematic, 0x10000)
		ADD_VAR(::BoolProperty, Cinematic, 0x8000)
		ADD_VAR(::BoolProperty, Cinematic, 0x4000)
		ADD_VAR(::BoolProperty, Cinematic, 0x2000)
		ADD_VAR(::BoolProperty, Cinematic, 0x1000)
		ADD_VAR(::BoolProperty, Unnamed, 0x800)
		ADD_VAR(::BoolProperty, Unnamed, 0x400)
		ADD_VAR(::BoolProperty, Unnamed, 0x200)
		ADD_VAR(::BoolProperty, Unnamed, 0x100)
		ADD_VAR(::BoolProperty, Unnamed, 0x80)
		ADD_VAR(::BoolProperty, Unnamed, 0x40)
		ADD_VAR(::BoolProperty, Skybox, 0x20)
		ADD_VAR(::BoolProperty, CompositeDynamic, 0x10)
		ADD_VAR(::BoolProperty, Dynamic, 0x8)
		ADD_VAR(::BoolProperty, Static, 0x4)
		ADD_VAR(::BoolProperty, BSP, 0x2)
		ADD_VAR(::BoolProperty, bInitialized, 0x1)
	};
}
#undef ADD_VAR
