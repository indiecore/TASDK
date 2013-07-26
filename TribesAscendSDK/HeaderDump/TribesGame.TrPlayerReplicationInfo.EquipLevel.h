#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrPlayerReplicationInfo.EquipLevel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EquipLevel
	{
	public:
		ADD_VAR(::ByteProperty, UpgradeLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EquipId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
