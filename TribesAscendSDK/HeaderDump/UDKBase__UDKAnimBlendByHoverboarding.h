#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByHoverboarding." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByHoverboarding : public UDKAnimBlendBase
	{
	public:
		ADD_VAR(::FloatProperty, FallTimeBeforeAnim, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoardLeanAmount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastActiveChildIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
