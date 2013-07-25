#pragma once
#include "Engine.UIDataStore_StringBase.h"
#include "Engine.LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_StringAliasMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_StringAliasMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_StringAliasMap : public UIDataStore_StringBase
	{
	public:
		ADD_VAR(::IntProperty, PlayerIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'MenuInputSets'!
		class LocalPlayer* GetPlayerOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_StringAliasMap.GetPlayerOwner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class LocalPlayer**)params;
			free(params);
			return returnVal;
		}
		int FindMappingWithFieldName(ScriptArray<wchar_t> FieldName, ScriptArray<wchar_t> SetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_StringAliasMap.FindMappingWithFieldName");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = FieldName;
			*(ScriptArray<wchar_t>*)(params + 12) = SetName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 24);
			free(params);
			return returnVal;
		}
		int GetStringWithFieldName(ScriptArray<wchar_t> FieldName, ScriptArray<wchar_t>& MappedString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_StringAliasMap.GetStringWithFieldName");
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
#undef ADD_STRUCT
