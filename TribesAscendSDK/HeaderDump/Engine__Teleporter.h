#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Teleporter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Teleporter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Teleporter : public NavigationPoint
	{
	public:
		ADD_VAR(::FloatProperty, LastFired, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetVelocity, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bCanTeleportVehicles, 0x40)
		ADD_VAR(::BoolProperty, bEnabled, 0x20)
		ADD_VAR(::BoolProperty, bReversesZ, 0x10)
		ADD_VAR(::BoolProperty, bReversesY, 0x8)
		ADD_VAR(::BoolProperty, bReversesX, 0x4)
		ADD_VAR(::BoolProperty, bChangesYaw, 0x2)
		ADD_VAR(::BoolProperty, bChangesVelocity, 0x1)
		ADD_VAR(::NameProperty, ProductRequired, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URL, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
