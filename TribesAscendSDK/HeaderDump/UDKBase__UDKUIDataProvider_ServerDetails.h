#pragma once
#include "UDKBase__UDKUIDataProvider_SimpleElementProvider.h"
#include "Engine__UIDataProvider_Settings.h"
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
		// Here lies the not-yet-implemented method 'GetSearchResultsProvider'
		// Here lies the not-yet-implemented method 'GetElementCount'
	};
}
#undef ADD_VAR
