#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrDaDStats.DaDScoreInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DaDScoreInfo
	{
	public:
		ADD_VAR(::IntProperty, CoreHealthPct, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCapacitorCOnline, 0x4)
		ADD_VAR(::BoolProperty, bCapacitorBOnline, 0x2)
		ADD_VAR(::BoolProperty, bCapacitorAOnline, 0x1)
		ADD_VAR(::IntProperty, GeneratorRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGeneratorOnline, 0x1)
	};
}
#undef ADD_VAR
