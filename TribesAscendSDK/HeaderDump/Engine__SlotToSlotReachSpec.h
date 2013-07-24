#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SlotToSlotReachSpec." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SlotToSlotReachSpec : public ForcedReachSpec
	{
	public:
		ADD_VAR(::ByteProperty, SpecDirection, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
