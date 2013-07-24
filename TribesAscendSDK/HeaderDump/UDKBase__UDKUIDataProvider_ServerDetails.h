#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataProvider_ServerDetails." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataProvider_ServerDetails : public UDKUIDataProvider_SimpleElementProvider
	{
	public:
		ADD_VAR(::IntProperty, SearchResultsRow, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
