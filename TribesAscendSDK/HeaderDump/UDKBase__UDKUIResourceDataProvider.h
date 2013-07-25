#pragma once
#include "Engine__UIResourceDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIResourceDataProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIResourceDataProvider : public UIResourceDataProvider
	{
	public:
		ADD_VAR(::StrProperty, IniName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRemoveOnPS3, 0x8)
		ADD_VAR(::BoolProperty, bRemoveOnPC, 0x4)
		ADD_VAR(::BoolProperty, bRemoveOn360, 0x2)
		ADD_VAR(::BoolProperty, bSearchAllInis, 0x1)
		ADD_VAR(::StrProperty, FriendlyName, 0xFFFFFFFF)
		bool IsFiltered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIResourceDataProvider.IsFiltered");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIResourceDataProvider.ShouldBeFiltered");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
