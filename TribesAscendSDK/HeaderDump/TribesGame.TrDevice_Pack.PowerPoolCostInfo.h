#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrDevice_Pack.PowerPoolCostInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrDevice_Pack.PowerPoolCostInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PowerPoolCostInfo
	{
	public:
		ADD_OBJECT(ScriptClass, m_TrFamilyInfo)
		ADD_VAR(::FloatProperty, m_fPowerPoolCostPerSec, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
