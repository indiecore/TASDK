#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUDKFrontEnd.ViewInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ViewInfo
	{
	public:
		ADD_VAR(::StrProperty, SWFName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ViewName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
