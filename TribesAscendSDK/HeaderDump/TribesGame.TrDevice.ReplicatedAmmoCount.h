#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrDevice.ReplicatedAmmoCount." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ReplicatedAmmoCount
	{
	public:
		ADD_VAR(::IntProperty, ClipAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CarriedAmmoCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
