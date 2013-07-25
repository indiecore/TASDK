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
		class UIDataProvider_Settings* GetSearchResultsProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataProvider_ServerDetails.GetSearchResultsProvider");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIDataProvider_Settings**)params;
			free(params);
			return returnVal;
		}
		int GetElementCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataProvider_ServerDetails.GetElementCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
