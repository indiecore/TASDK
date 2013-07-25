#pragma once
#include "Engine.UIDataStore_StringAliasMap.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataStore_StringAliasMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_StringAliasMap : public UIDataStore_StringAliasMap
	{
	public:
		ADD_VAR(::IntProperty, FakePlatform, 0xFFFFFFFF)
		int GetStringWithFieldName(ScriptArray<wchar_t> FieldName, ScriptArray<wchar_t>& MappedString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_StringAliasMap.GetStringWithFieldName");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 12) = MappedString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MappedString = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(int*)(params + 24);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
