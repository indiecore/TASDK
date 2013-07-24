#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqVar_Group." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqVar_Group : public SeqVar_Object
	{
	public:
		ADD_VAR(::BoolProperty, bCachedList, 0x1)
		ADD_VAR(::NameProperty, GroupName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
