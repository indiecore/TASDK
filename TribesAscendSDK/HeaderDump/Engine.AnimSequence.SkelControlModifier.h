#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimSequence.SkelControlModifier." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SkelControlModifier
	{
	public:
		ADD_VAR(::NameProperty, SkelControlName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
