#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSummaryHelper." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSummaryHelper : public Object
	{
	public:
		ADD_VAR(::IntProperty, AWARD_TIER_SIZE, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
