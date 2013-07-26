#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrGame_TrStorm.Carrier." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Carrier
	{
	public:
		ADD_VAR(::ByteProperty, TeamNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CoreHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ShieldHealth, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
