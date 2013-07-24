#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimMetaData_SkelControl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimMetaData_SkelControl : public AnimMetaData
	{
	public:
		ADD_VAR(::NameProperty, SkelControlName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFullControlOverController, 0x1)
	};
}
#undef ADD_VAR
