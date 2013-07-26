#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrUser.NewItem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NewItem
	{
	public:
		ADD_VAR(::IntProperty, ItemId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClassId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
